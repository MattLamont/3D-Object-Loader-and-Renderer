#include "OpenGLFrame.h"
#include <iostream>
#include <ctime>


OpenGLFrame::OpenGLFrame(QWidget *parent) : QGLWidget(parent) 
{
	superWidget = parent;

	light1 = new Light();
	light2 = new Light();
	light3 = new Light();

	material = new Material();
	icosahedron = new Icosahedron();
	environmentMap = new EnvironmentMap();
	CURRENT_OBJECT = OBJECT::TEAPOT;
	currentObject = &object;

	zoom = -2.0;
	previousX = 0;
	previousY = 0;
	currentX = 0;
	currentY = 0;
	rotateX = 0.0;
	rotateY = 0.0;
	panX = 0.0;
	panY = 0.0;
	currentButton = Qt::MouseButton::LeftButton;

	shaderProgram = new QGLShaderProgram();
	usingShaderProgram = false;

	m_context = new QOpenGLContext;
    m_context->create();

	CURRENT_SHADER = SMOOTH_SHADER;

	 timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(update()));
     timer->start(0);

}

OpenGLFrame::~OpenGLFrame()
{
	delete light1;
	delete light2;
	delete light3;
	delete material;
	delete icosahedron;
	delete environmentMap;
	delete shaderProgram;
}

void OpenGLFrame::initializeGL()
{
	glClearColor( 0.1 , 0.2 , 0.3 , 0.0 );

	glEnable( GL_DEPTH_TEST );
	//glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);

	glDisable( GL_BLEND );

	initializeGLFunctions();
}


void OpenGLFrame::resizeGL( int w , int h )
{
	w = superWidget->width();
	h = superWidget->height();

	// Compute aspect ratio of the new window
   if (h == 0) h = 1;                // To prevent divide by 0
		GLfloat aspect = (GLfloat)w / (GLfloat)h;
   
	
   // Set the viewport to cover the new window
   glViewport(0, 0, w, h);
 
   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset the projection matrix
   if (w >= h) 
   {
		gluPerspective( 60 , aspect , 0.05 , 100.0 ); 
   } 
   else 
   {
		gluPerspective( 60 , aspect , 0.05 , 100.0 ); 
   }
}

void OpenGLFrame::paintGL()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	this->setupTransformations();
	this->setupEnvironmentMap();
	this->setupLights();
	this->setupMaterial( material );
	this->setupGrid();
	this->refreshShader();
	this->drawObject();
}


OpenGLFrame::Light::Light()
{
	enabled = true;

	ambient_r = 0.0;
	ambient_g = 0.0;
	ambient_b = 0.0;

	diffuse_r = 1.0;
	diffuse_g = 1.0;
	diffuse_b = 1.0;

	specular_r = 1.0;
	specular_g = 1.0;
	specular_b = 1.0;

	position_x = -1.0;
	position_y = 1.0;
	position_z = 1.0;

	direction_x = 0.0;
	direction_y = 0.0;
	direction_z = -1.0;

	attenuation_constant = 1.0;
	attenuation_linear = 0.0;
	attenuation_quadratic = 0.0;

	spotlight_cutoff = 45.0;

	light_type = POINT_LIGHT;
}

OpenGLFrame::Material::Material()
{
	useDefault = false;

	ambient_r = 0.2;
	ambient_g = 0.2;
	ambient_b = 0.2;

	diffuse_r = 0.8;
	diffuse_g = 0.8;
	diffuse_b = 0.8;

	specular_r = 0.0;
	specular_g = 0.0;
	specular_b = 0.0;

	emissive_r = 0.0;
	emissive_g = 0.0;
	emissive_b = 0.0;

	shininess = 0.0;
}

OpenGLFrame::EnvironmentMap::EnvironmentMap()
{
	enabled = false;
	mipmapsEnabled = true;
	mode = GL_REFLECTION_MAP_EXT;
	wrap = GL_CLAMP;
}

void OpenGLFrame::setupMaterial( Material *currentMaterial )
{
	
	if( currentMaterial->useDefault )
	{
		GLfloat mat_ambient[] = { 0.2 , 0.2 , 0.2 , 1.0 };
		GLfloat mat_diffuse[] = { 0.8 , 0.8 , 0.8 , 1.0 };
		GLfloat mat_specular[] = { 0.0 , 0.0 , 0.0 , 1.0 };
		GLfloat mat_emissive[] = { 0.0 , 0.0 , 0.0 , 1.0 };
		GLfloat mat_shininess[] = { 0.0 };

		glMaterialfv( GL_FRONT_AND_BACK , GL_AMBIENT , mat_ambient );
		glMaterialfv( GL_FRONT_AND_BACK , GL_DIFFUSE , mat_diffuse );
		glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular );
		glMaterialfv( GL_FRONT_AND_BACK , GL_EMISSION , mat_emissive );
		glMaterialfv( GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess );
	}

	else
	{
		GLfloat mat_ambient[] = { currentMaterial->ambient_r , currentMaterial->ambient_g , currentMaterial->ambient_b , 1.0 };
		GLfloat mat_diffuse[] = { currentMaterial->diffuse_r , currentMaterial->diffuse_g , currentMaterial->diffuse_b , 1.0 };
		GLfloat mat_specular[] = { currentMaterial->specular_r , currentMaterial->specular_g , currentMaterial->specular_b , 1.0 };
		GLfloat mat_emissive[] = { currentMaterial->emissive_r , currentMaterial->specular_g , currentMaterial->specular_b , 1.0 };
		GLfloat mat_shininess[] = { currentMaterial->shininess };

		glMaterialfv( GL_FRONT_AND_BACK , GL_AMBIENT , mat_ambient );
		glMaterialfv( GL_FRONT_AND_BACK , GL_DIFFUSE , mat_diffuse );
		glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular );
		glMaterialfv( GL_FRONT_AND_BACK , GL_EMISSION , mat_emissive );
		glMaterialfv( GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess );
	}
}

void OpenGLFrame::setupLights()
{
	//configure light 1
	if( light1->enabled )
	{
		//set ambient light
		GLfloat light_ambient[] = { light1->ambient_r , light1->ambient_g , light1->ambient_b , 1.0 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

		//set diffuse light
		GLfloat light_diffuse[] = { light1->diffuse_r , light1->diffuse_g , light1->diffuse_b , 1.0 };
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

		//set specular light
		GLfloat light_specular[] = { light1->specular_r , light1->specular_g , light1->specular_b , 1.0 };
		glLightfv( GL_LIGHT0 , GL_SPECULAR , light_specular );

		//set light position
		GLfloat light_position[] = { light1->position_x , light1->position_y , light1->position_z , 1.0 };
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);

		//set light attenuation
		glLightf( GL_LIGHT0 , GL_CONSTANT_ATTENUATION , light1->attenuation_constant );
		glLightf( GL_LIGHT0 , GL_LINEAR_ATTENUATION , light1->attenuation_linear );
		glLightf( GL_LIGHT0 , GL_QUADRATIC_ATTENUATION , light1->attenuation_quadratic );

		//if a spotlight is chosen, then setup the direction and cutoff. Otherwise setup the defaults
		GLfloat light_direction[4];
		if( light1->light_type == Light::LIGHT_TYPE::SPOT_LIGHT )
		{
			light_direction[0] = light1->direction_x;
			light_direction[1] = light1->direction_y;
			light_direction[2] = light1->direction_z;
			light_direction[3] = 1.0;
			glLightfv( GL_LIGHT0 , GL_SPOT_DIRECTION , light_direction );
			glLightf( GL_LIGHT0 , GL_SPOT_CUTOFF , light1->spotlight_cutoff );
		}
		else
		{
			light_direction[0] = 0.0;
			light_direction[1] = 0.0;
			light_direction[2] = -1.0;
			light_direction[3] = 1.0;
			glLightfv( GL_LIGHT0 , GL_SPOT_DIRECTION , light_direction );
			glLightf( GL_LIGHT0 , GL_SPOT_CUTOFF , 180.0 );
		}
		
		//enable the light
		glEnable(GL_LIGHT0);

		glBegin( GL_POLYGON );
			glVertex3f( light1->position_x , light1->position_y , light1->position_z );
			glVertex3f( light1->position_x + 0.1 , light1->position_y , light1->position_z );
			glVertex3f( light1->position_x + 0.1 , light1->position_y + 0.1 , light1->position_z );
			glVertex3f( light1->position_x , light1->position_y + 0.1 , light1->position_z );
		glEnd();
		

	}

	else
	{
		glDisable( GL_LIGHT0 );
	}

	//configure light 2
	if( light2->enabled )
	{
		//set ambient light
		GLfloat light_ambient[] = { light2->ambient_r , light2->ambient_g , light2->ambient_b , 1.0 };
		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);

		//set diffuse light
		GLfloat light_diffuse[] = { light2->diffuse_r , light2->diffuse_g , light2->diffuse_b , 1.0 };
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);

		//set specular light
		GLfloat light_specular[] = { light2->specular_r , light2->specular_g , light2->specular_b , 1.0 };
		glLightfv( GL_LIGHT1 , GL_SPECULAR , light_specular );

		//set light position
		GLfloat light_position[] = { light2->position_x , light2->position_y , light2->position_z , 1.0 };
		glLightfv(GL_LIGHT1, GL_POSITION, light_position);

		//set light attenuation
		glLightf( GL_LIGHT1 , GL_CONSTANT_ATTENUATION , light2->attenuation_constant );
		glLightf( GL_LIGHT1 , GL_LINEAR_ATTENUATION , light2->attenuation_linear );
		glLightf( GL_LIGHT1 , GL_QUADRATIC_ATTENUATION , light2->attenuation_quadratic );

		//if a spotlight is chosen, then setup the direction and cutoff. Otherwise setup the defaults
		GLfloat light_direction[4];
		if( light2->light_type == Light::LIGHT_TYPE::SPOT_LIGHT )
		{
			light_direction[0] = light2->direction_x;
			light_direction[1] = light2->direction_y;
			light_direction[2] = light2->direction_z;
			light_direction[3] = 1.0;
			glLightfv( GL_LIGHT1 , GL_SPOT_DIRECTION , light_direction );
			glLightf( GL_LIGHT1 , GL_SPOT_CUTOFF , light2->spotlight_cutoff );
		}
		else
		{
			light_direction[0] = 0.0;
			light_direction[1] = 0.0;
			light_direction[2] = -1.0;
			light_direction[3] = 1.0;
			glLightfv( GL_LIGHT1 , GL_SPOT_DIRECTION , light_direction );
			glLightf( GL_LIGHT1 , GL_SPOT_CUTOFF , 180.0 );
		}
		
		//enable the light
		glEnable(GL_LIGHT1);

		glBegin( GL_POLYGON );
			glVertex3f( light2->position_x , light2->position_y , light2->position_z );
			glVertex3f( light2->position_x + 0.1 , light2->position_y , light2->position_z );
			glVertex3f( light2->position_x + 0.1 , light2->position_y + 0.1 , light2->position_z );
			glVertex3f( light2->position_x , light2->position_y + 0.1 , light2->position_z );
		glEnd();
	}

	else
	{
		glDisable( GL_LIGHT1 );
	}

	//configure light 3
	if( light3->enabled )
	{
		//set ambient light
		GLfloat light_ambient[] = { light3->ambient_r , light3->ambient_g , light3->ambient_b , 1.0 };
		glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);

		//set diffuse light
		GLfloat light_diffuse[] = { light3->diffuse_r , light3->diffuse_g , light3->diffuse_b , 1.0 };
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);

		//set specular light
		GLfloat light_specular[] = { light3->specular_r , light3->specular_g , light3->specular_b , 1.0 };
		glLightfv( GL_LIGHT2 , GL_SPECULAR , light_specular );

		//set light position
		GLfloat light_position[] = { light3->position_x , light3->position_y , light3->position_z , 1.0 };
		glLightfv(GL_LIGHT2, GL_POSITION, light_position);

		//set light attenuation
		glLightf( GL_LIGHT2 , GL_CONSTANT_ATTENUATION , light3->attenuation_constant );
		glLightf( GL_LIGHT2 , GL_LINEAR_ATTENUATION , light3->attenuation_linear );
		glLightf( GL_LIGHT2 , GL_QUADRATIC_ATTENUATION , light3->attenuation_quadratic );

		//if a spotlight is chosen, then setup the direction and cutoff. Otherwise setup the defaults
		GLfloat light_direction[4];
		if( light3->light_type == Light::LIGHT_TYPE::SPOT_LIGHT )
		{
			light_direction[0] = light3->direction_x;
			light_direction[1] = light3->direction_y;
			light_direction[2] = light3->direction_z;
			light_direction[3] = 1.0;
			glLightfv( GL_LIGHT2 , GL_SPOT_DIRECTION , light_direction );
			glLightf( GL_LIGHT2 , GL_SPOT_CUTOFF , light3->spotlight_cutoff );
		}
		else
		{
			light_direction[0] = 0.0;
			light_direction[1] = 0.0;
			light_direction[2] = -1.0;
			light_direction[3] = 1.0;
			glLightfv( GL_LIGHT2 , GL_SPOT_DIRECTION , light_direction );
			glLightf( GL_LIGHT2 , GL_SPOT_CUTOFF , 180.0 );
		}
		
		//enable the light
		glEnable(GL_LIGHT2);

		glBegin( GL_POLYGON );
			glVertex3f( light3->position_x , light3->position_y , light3->position_z );
			glVertex3f( light3->position_x + 0.1 , light3->position_y , light3->position_z );
			glVertex3f( light3->position_x + 0.1 , light3->position_y + 0.1 , light3->position_z );
			glVertex3f( light3->position_x , light3->position_y + 0.1 , light3->position_z );
		glEnd();
		

	}

	else
	{
		glDisable( GL_LIGHT2 );
	}
}

void OpenGLFrame::setupEnvironmentMap()
{

	if( environmentMap->enabled == true )
	{
		
		if( environmentMap->mipmapsEnabled == true ) 
		{

			gluBuild2DMipmaps( GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT , environmentMap->rightFace->components,
				environmentMap->rightFace->width, environmentMap->rightFace->height,
				environmentMap->rightFace->format, GL_UNSIGNED_BYTE, environmentMap->rightFace->pixels);

			gluBuild2DMipmaps( GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT , environmentMap->leftFace->components,
				environmentMap->leftFace->width, environmentMap->leftFace->height,
				environmentMap->leftFace->format, GL_UNSIGNED_BYTE, environmentMap->leftFace->pixels);

			gluBuild2DMipmaps( GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT , environmentMap->topFace->components,
				environmentMap->topFace->width, environmentMap->topFace->height,
				environmentMap->topFace->format, GL_UNSIGNED_BYTE, environmentMap->topFace->pixels);

			gluBuild2DMipmaps( GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT , environmentMap->bottomFace->components,
				environmentMap->bottomFace->width, environmentMap->bottomFace->height,
				environmentMap->bottomFace->format, GL_UNSIGNED_BYTE, environmentMap->bottomFace->pixels);

			gluBuild2DMipmaps( GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT , environmentMap->frontFace->components,
				environmentMap->frontFace->width, environmentMap->frontFace->height,
				environmentMap->frontFace->format, GL_UNSIGNED_BYTE, environmentMap->frontFace->pixels);

			gluBuild2DMipmaps( GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT , environmentMap->backFace->components,
				environmentMap->backFace->width, environmentMap->backFace->height,
				environmentMap->backFace->format, GL_UNSIGNED_BYTE, environmentMap->backFace->pixels);
		}

		else
		{
			glTexImage2D( GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT , 0 , environmentMap->rightFace->components ,
				environmentMap->rightFace->width , environmentMap->rightFace->height , 0 ,
				environmentMap->rightFace->format , GL_UNSIGNED_BYTE , environmentMap->rightFace->pixels );

			glTexImage2D( GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT , 0 , environmentMap->leftFace->components ,
				environmentMap->leftFace->width , environmentMap->leftFace->height , 0 ,
				environmentMap->leftFace->format , GL_UNSIGNED_BYTE , environmentMap->leftFace->pixels );

			glTexImage2D( GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT , 0 , environmentMap->topFace->components ,
				environmentMap->topFace->width , environmentMap->topFace->height , 0 ,
				environmentMap->topFace->format , GL_UNSIGNED_BYTE , environmentMap->topFace->pixels );

			glTexImage2D( GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT , 0 , environmentMap->bottomFace->components ,
				environmentMap->bottomFace->width , environmentMap->bottomFace->height , 0 ,
				environmentMap->bottomFace->format , GL_UNSIGNED_BYTE , environmentMap->bottomFace->pixels );

			glTexImage2D( GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT , 0 , environmentMap->frontFace->components ,
				environmentMap->frontFace->width , environmentMap->frontFace->height , 0 ,
				environmentMap->frontFace->format , GL_UNSIGNED_BYTE , environmentMap->frontFace->pixels );

			glTexImage2D( GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT , 0 , environmentMap->backFace->components ,
				environmentMap->backFace->width , environmentMap->backFace->height , 0 ,
				environmentMap->backFace->format , GL_UNSIGNED_BYTE , environmentMap->backFace->pixels );
		}
		

		if( environmentMap->mipmapsEnabled == true ) 
		{
			glTexParameteri(GL_TEXTURE_CUBE_MAP_EXT, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_CUBE_MAP_EXT, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		} 
		
		else 
		{
			glTexParameteri(GL_TEXTURE_CUBE_MAP_EXT, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_CUBE_MAP_EXT, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}

		glEnable(GL_TEXTURE_CUBE_MAP_EXT);

		assert(environmentMap->mode == GL_NORMAL_MAP_EXT || environmentMap->mode == GL_REFLECTION_MAP_EXT);
		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, environmentMap->mode);
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, environmentMap->mode);
		glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, environmentMap->mode);

		glTexParameteri(GL_TEXTURE_CUBE_MAP_EXT, GL_TEXTURE_WRAP_S, environmentMap->wrap);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_EXT, GL_TEXTURE_WRAP_T, environmentMap->wrap);

		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		glEnable(GL_TEXTURE_GEN_R);
	}

	else
	{
		glDisable( GL_TEXTURE_CUBE_MAP_EXT );
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
		glDisable(GL_TEXTURE_GEN_R);
	}
}

void OpenGLFrame::setShader( SHADER s )
{
	if( usingShaderProgram )
		shaderProgram->release();

	this->CURRENT_SHADER = s;

	switch( s )
	{
	case FLAT_SHADER:
		glShadeModel( GL_FLAT );
		usingShaderProgram = false;
		break;

	case SMOOTH_SHADER:
		glShadeModel( GL_SMOOTH );
		usingShaderProgram = false;
		break;

	case NORMAL_MAPPING:
		setupNormalMappingShader( "Resources/normal_mapping.vert" , "Resources/normal_mapping.frag" );
		//setupNormalMappingShader( "Resources/toonf2.vert" , "Resources/toonf2.frag" );
		usingShaderProgram = true;
		break;

	case PER_PIXEL_SHADING:
		setupPerPixelShader( "Resources/per_pixel_shading.vert" , "Resources/per_pixel_shading.frag" );
		usingShaderProgram = true;
		break;

	case PHONG_SHADING:
		setupPhongShader( "Resources/phong_shading.vert" , "Resources/phong_shading.frag" );
		usingShaderProgram = true;
		break;
		
	case CUSTOM_SHADER1:
		
		setupCustomShader1( "Resources/custom_shader.vert" , "Resources/custom_shader.frag" );
		usingShaderProgram = true;
		break;

	case TOON_SHADER:
		setupToonShader( "Resources/toonf2.vert" , "Resources/toonf2.frag" );
		usingShaderProgram = true;
		break;

	case CUSTOM_SHADER2:
		setupCustomShader2( "Resources/custom_shader_2.vert" , "Resources/custom_shader_2.frag" );
		usingShaderProgram = true;
		break;
	}

	this->updateGL();
}

void OpenGLFrame::setupToonShader( QString vertexFilename , QString fragmentFilename )
{
	shaderProgram = new QGLShaderProgram();

	shaderProgram->addShaderFromSourceFile(QGLShader::Vertex, vertexFilename );	
	shaderProgram->addShaderFromSourceFile(QGLShader::Fragment, fragmentFilename );
		
	shaderProgram->link();
	shaderProgram->bind();

	QString log = shaderProgram->log();
	std::cout << log.toStdString();
}


void OpenGLFrame::setupCustomShader2( QString vertexFilename , QString fragmentFilename )
{
	shaderProgram = new QGLShaderProgram();

	shaderProgram->addShaderFromSourceFile(QGLShader::Vertex, vertexFilename );	
	shaderProgram->addShaderFromSourceFile(QGLShader::Fragment, fragmentFilename );
		
	shaderProgram->link();
	shaderProgram->bind();

	QString log = shaderProgram->log();
	std::cout << log.toStdString();
}

void OpenGLFrame::setupCustomShader1( QString vertexFilename , QString fragmentFilename )
{

	shaderProgram = new QGLShaderProgram();

	shaderProgram->addShaderFromSourceFile(QGLShader::Vertex, vertexFilename );	
	shaderProgram->addShaderFromSourceFile(QGLShader::Fragment, fragmentFilename );
		
	shaderProgram->link();
	shaderProgram->bind();

	QPoint p = this->mapFromGlobal(QCursor::pos());
	shaderProgram->setUniformValue("mouse", p.x() , p.y() );
	GLfloat curTime = std::time( 0 );
	shaderProgram->setUniformValue("time" , curTime );
	//GLfloat res = this->width / this->height;
	shaderProgram->setUniformValue("resolution" , this->width() , this->height() );

	QString log = shaderProgram->log();
	std::cout << log.toStdString();

}


void OpenGLFrame::setupNormalMappingShader( QString vertexFilename , QString fragmentFilename )
{

	shaderProgram = new QGLShaderProgram();

	shaderProgram->addShaderFromSourceFile(QGLShader::Vertex, vertexFilename );	
	shaderProgram->addShaderFromSourceFile(QGLShader::Fragment, fragmentFilename );
		
	shaderProgram->link();
	shaderProgram->bind();

	QString log = shaderProgram->log();
	std::cout << log.toStdString();

	texture = LoadTexture("Images/colour_map.raw", 256, 256);  
	normal_texture = LoadTexture("Images/normal_map.raw", 256, 256); 

	glActiveTexture(GL_TEXTURE1);  
	glEnable(GL_TEXTURE_2D);  
	//int texture_location = shaderProgram->uniformLocation( "color_texture");
	shaderProgram->setUniformValue( "color_texture" , texture ); 
	glBindTexture(GL_TEXTURE_2D, texture);

	glActiveTexture(GL_TEXTURE2);  
	glEnable(GL_TEXTURE_2D);  
	//int normal_location = shaderProgram->uniformLocation( "normal_texture");
	shaderProgram->setUniformValue( "normal_texture" , normal_texture );
	glBindTexture(GL_TEXTURE_2D, normal_texture);

	/*
	glBegin(GL_QUADS);  
	glTexCoord2f(0.0f, 0.0f);  
	glVertex3f(-1.0f, -1.0f, 0.0f);  
  
	glTexCoord2f(1.0f, 0.0f);  
	glVertex3f(1.0f, -1.0f, 0.0f);  
  
	glTexCoord2f(1.0f, 1.0f);  
	glVertex3f(1.0f, 1.0f, 0.0f);  
  
	glTexCoord2f(0.0f, 1.0f);  
	glVertex3f(-1.0f, 1.0f, 0.0f);  
	glEnd();  

	glFlush();

	glutSolidTeapot( 0.5 );
	*/
	/*
	glFlush();
  
	glActiveTexture(GL_TEXTURE1);  
	glBindTexture(GL_TEXTURE_2D, 0);  
	glDisable(GL_TEXTURE_2D);  
  
	glActiveTexture(GL_TEXTURE0);  
	glBindTexture(GL_TEXTURE_2D, 0);  
	glDisable(GL_TEXTURE_2D); 
	*/
}

void OpenGLFrame::setupPerPixelShader( QString vertexFilename , QString fragmentFilename )
{
	shaderProgram = new QGLShaderProgram();

	shaderProgram->addShaderFromSourceFile(QGLShader::Vertex, vertexFilename );	
	shaderProgram->addShaderFromSourceFile(QGLShader::Fragment, fragmentFilename );
		
	shaderProgram->link();
	shaderProgram->bind();

	QString log = shaderProgram->log();
	std::cout << log.toStdString();
}

void OpenGLFrame::setupPhongShader( QString vertexFilename , QString fragmentFilename )
{
	shaderProgram = new QGLShaderProgram();

	shaderProgram->addShaderFromSourceFile(QGLShader::Vertex, vertexFilename );	
	shaderProgram->addShaderFromSourceFile(QGLShader::Fragment, fragmentFilename );
		
	shaderProgram->link();
	shaderProgram->bind();

	QString log = shaderProgram->log();
	std::cout << log.toStdString();
}

void OpenGLFrame::setupTransformations()
{
	glTranslatef( panX , panY , zoom );
	glRotatef( rotateX , 0.0 , 1.0 , 0.0 );
	glRotatef( rotateY , 1.0 , 0.0 , 0.0 );
}

void OpenGLFrame::setupGrid()
{
	GLfloat gridSpace = 0.0;
	for( int i = 0 ; i < 10 ; i++ )
	{
		glBegin( GL_POLYGON );
			glVertex3f( -1.0 , -1.0 , -0.5 + gridSpace ); 
			glVertex3f( 1.0 , -1.0 , -0.5 + gridSpace );
			glVertex3f( 1.0 , -1.0 , -0.51 + gridSpace );
			glVertex3f( -1.0 , -1.0 , -0.51 + gridSpace );
		glEnd();
		gridSpace = gridSpace + 0.1;
	}

	gridSpace = 0.0;
	for( int i = 0 ; i < 20 ; i++ )
	{
		glBegin( GL_POLYGON );
			glVertex3f( -1.0 + gridSpace , -1.0 , -0.5 ); 
			glVertex3f( -0.99 + gridSpace , -1.0 , -0.5  );
			glVertex3f( -0.99 + gridSpace , -1.0 , 0.5 );
			glVertex3f( -1.0 + gridSpace , -1.0 , 0.5 );
		glEnd();
		gridSpace = gridSpace + 0.1;
	}
}

void OpenGLFrame::setDrawableObject( OBJECT object )
{
	CURRENT_OBJECT = object;
	updateGL();
}

void OpenGLFrame::drawObject()
{
	switch( CURRENT_OBJECT )
	{
	case ICOSAHEDRON:
		icosahedron->setSubdivisionCount( Icosahedron::SUBDIVISION_COUNT::LEVEL_1280 );
		icosahedron->draw();
		break;
	case TEAPOT:
		glutSolidTeapot( 0.5 );
		break;

	case FILE_OBJECT:
		drawFileObject();
		break;
	}
}

void OpenGLFrame::drawFileObject()
{
	glScalef( 0.01 , 0.01 , 0.01 );


	int l_index;
	glBegin(GL_TRIANGLES); // glBegin and glEnd delimit the vertices that define a primitive (in our case triangles)
    for (l_index=0;l_index<currentObject->polygons_qty;l_index++)
    {
        //----------------- FIRST VERTEX -----------------
		glNormal3f( currentObject->vertex[ currentObject->polygon[l_index].a ].x,
                    currentObject->vertex[ currentObject->polygon[l_index].a ].y,
                    currentObject->vertex[ currentObject->polygon[l_index].a ].z); 
        // Texture coordinates of the first vertex
        glVertex3f( currentObject->vertex[ currentObject->polygon[l_index].a ].x,
                    currentObject->vertex[ currentObject->polygon[l_index].a ].y,
                    currentObject->vertex[ currentObject->polygon[l_index].a ].z); 

        //----------------- SECOND VERTEX -----------------
		glNormal3f( currentObject->vertex[ currentObject->polygon[l_index].b ].x,
                    currentObject->vertex[ currentObject->polygon[l_index].b ].y,
                    currentObject->vertex[ currentObject->polygon[l_index].b ].z);
        // Coordinates of the second vertex
        glVertex3f( currentObject->vertex[ currentObject->polygon[l_index].b ].x,
                    currentObject->vertex[ currentObject->polygon[l_index].b ].y,
                    currentObject->vertex[ currentObject->polygon[l_index].b ].z);
        
        //----------------- THIRD VERTEX -----------------
		glNormal3f( currentObject->vertex[ currentObject->polygon[l_index].c ].x,
                    currentObject->vertex[ currentObject->polygon[l_index].c ].y,
                    currentObject->vertex[ currentObject->polygon[l_index].c ].z);
        // Coordinates of the Third vertex
        glVertex3f( currentObject->vertex[ currentObject->polygon[l_index].c ].x,
                    currentObject->vertex[ currentObject->polygon[l_index].c ].y,
                    currentObject->vertex[ currentObject->polygon[l_index].c ].z);
    }
    glEnd();

    glFlush(); // This force the execution of OpenGL commands

}


void OpenGLFrame::wheelEvent ( QWheelEvent *event )
{
	GLfloat x = event->delta() / 120;
	zoom += x / 10;
	updateGL();
}

void OpenGLFrame::mousePressEvent( QMouseEvent *event )
{
	previousX = event->x();
	previousY = event->y();

	currentButton = event->button();
}

void OpenGLFrame::mouseMoveEvent( QMouseEvent *event )
{
	GLint deltaX;
	GLint deltaY;

	currentX = event->x();
	currentY = event->y();

	deltaX = previousX - currentX;
	deltaY = previousY - currentY;

	if( currentButton == Qt::MouseButton::LeftButton )
	{

		if( deltaX > 0 )
			rotateX += -5.0;

		else if( deltaX < 0 )
			rotateX += 5.0;

		else
			rotateX += 0.0;

		if( deltaY > 0 )
			rotateY += -5.0;

		else if( deltaY < 0 )
			rotateY += 5.0;

		else
			rotateY += 0.0;

		previousX = currentX;
		previousY = currentY;

	}

	else if( currentButton == Qt::MouseButton::RightButton )
	{
		deltaX = deltaX / 10;
		deltaY = deltaY / 10;

		if( deltaX > 0 )
			panX += -0.1;

		else if( deltaX < 0 )
			panX += 0.1;
		
		else
			panX += 0;

		if( deltaY > 0 )
			panY += -0.1;

		else if( deltaY < 0 )
			panY += 0.1;

		else
			panY += 0;

		previousX = currentX;
		previousY = currentY;
	}

	else
	{
		std::cout << "Error: unrecognized button\n";
	}

	this->updateGL();
}

GLuint OpenGLFrame::LoadTexture( const char * filename, int width, int height )  
{  
	GLuint texture;  
	unsigned char * data;  
	FILE * file;  
  
	//The following code will read in our RAW file  
	file = fopen( filename, "rb" );  
  
	if ( file == NULL )
	{
		std::cout << "Didn't find file.\n";
		return 0; 
	}
	data = (unsigned char *)malloc( width * height * 3 );  
	fread( data, width * height * 3, 1, file );  
  
	fclose( file );  
  
	glGenTextures( 1, &texture ); //generate the texture with the loaded data  
	glBindTexture( GL_TEXTURE_2D, texture ); //bind the texture to it’s array  
  
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE ); //set texture environment parameters  
  
	//And if you go and use extensions, you can use Anisotropic filtering textures which are of an  
	//even better quality, but this will do for now.  
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);  
  
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);  
  
	//Here we are setting the parameter to repeat the texture instead of clamping the texture  
	//to the edge of our shape.  
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );  
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );  
  
	//Generate the texture  
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);  
  
	free( data ); //free the texture  
  
	return texture; //return whether it was successfull  
	}  
  
void OpenGLFrame::FreeTexture( GLuint texture )  
{  
	glDeleteTextures( 1, &texture );  
} 

void OpenGLFrame::makeObject()
{
    static const int coords[6][4][3] = {
        { { +1, -1, -1 }, { -1, -1, -1 }, { -1, +1, -1 }, { +1, +1, -1 } },
        { { +1, +1, -1 }, { -1, +1, -1 }, { -1, +1, +1 }, { +1, +1, +1 } },
        { { +1, -1, +1 }, { +1, -1, -1 }, { +1, +1, -1 }, { +1, +1, +1 } },
        { { -1, -1, -1 }, { -1, -1, +1 }, { -1, +1, +1 }, { -1, +1, -1 } },
        { { +1, -1, +1 }, { -1, -1, +1 }, { -1, -1, -1 }, { +1, -1, -1 } },
        { { -1, -1, +1 }, { +1, -1, +1 }, { +1, +1, +1 }, { -1, +1, +1 } }
    };

    for (int j=0; j < 6; ++j) {
        textures[j] = bindTexture
            (QPixmap(QString("Images/side%1.png").arg(j + 1)), GL_TEXTURE_2D);
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            texCoords.append
                (QVector2D(j == 0 || j == 3, j == 0 || j == 1));
            vertices.append
                (QVector3D(0.2 * coords[i][j][0], 0.2 * coords[i][j][1],
                        0.2 * coords[i][j][2]));
        }
    }
}

void OpenGLFrame::refreshShader()
{
	switch( CURRENT_SHADER )
	{
	case CUSTOM_SHADER1:
		QPoint p = this->mapFromGlobal(QCursor::pos());
		shaderProgram->setUniformValue("mouse", p.x() , p.y() );
		GLfloat curTime = std::time( 0 );
		shaderProgram->setUniformValue("time" , curTime );
		//GLfloat res = this->width / this->height;
		shaderProgram->setUniformValue("resolution" , this->width() , this->height() );
		break;
	}
}

void OpenGLFrame::update()
{
	this->updateGL();
}

