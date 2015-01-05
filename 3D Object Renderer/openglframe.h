#ifndef OPENGLFRAME_H
#define OPENGLFRAME_H

//#define GLEW_STATIC

//#include "GL/glew.h"
#include <QGLWidget>
#include <QtOpenGl/QGLWidget>
#include <QtOpenGl/Qglcontext>
#include <QtOpenGL/qglshaderprogram.h>
#include <QMouseEvent>
#include <qglfunctions.h>
//#include "Shader.h"
#include <assert.h>
extern "C" {
#include "tga.h"
}

#include "GL/glut.h"
#include "Icosahedron.h"
#include "qtimer.h"

#define MAX_VERTICES 8000 
#define MAX_POLYGONS 8000 


class OpenGLFrame : public QGLWidget , public QGLFunctions
{
    Q_OBJECT

public:

	enum SHADER
	{
		FLAT_SHADER,
		SMOOTH_SHADER,
		NORMAL_MAPPING,
		PER_PIXEL_SHADING,
		PHONG_SHADING,
		CUSTOM_SHADER1,
		CUSTOM_SHADER2,
		TOON_SHADER
	};

	class EnvironmentMap
	{
	public:

		enum ENV_MAP_FACE
		{
			TOP_FACE,
			BOTTOM_FACE,
			LEFT_FACE,
			RIGHT_FACE,
			BACK_FACE,
			FRONT_FACE
		};

		EnvironmentMap();

		bool enabled;
		bool mipmapsEnabled;
		int mode;
		int wrap;

		gliGenericImage *topFace;
		gliGenericImage *bottomFace;
		gliGenericImage *leftFace;
		gliGenericImage *rightFace;
		gliGenericImage *backFace;
		gliGenericImage *frontFace;

	};

	class Light
	{
	public:

		Light();

		GLboolean enabled;

		GLfloat ambient_r;
		GLfloat ambient_g;
		GLfloat ambient_b;

		GLfloat diffuse_r;
		GLfloat diffuse_g;
		GLfloat diffuse_b;

		GLfloat specular_r;
		GLfloat specular_g;
		GLfloat specular_b;

		GLfloat position_x;
		GLfloat position_y;
		GLfloat position_z;

		GLfloat direction_x;
		GLfloat direction_y;
		GLfloat direction_z;

		GLfloat attenuation_constant;
		GLfloat attenuation_linear;
		GLfloat attenuation_quadratic;

		GLfloat spotlight_cutoff;

		enum LIGHT_TYPE
		{
			POINT_LIGHT,
			SPOT_LIGHT
		};

		LIGHT_TYPE light_type;
	};

	class Material
	{
	public:

		Material();

		GLboolean useDefault;

		GLfloat ambient_r;
		GLfloat ambient_g;
		GLfloat ambient_b;

		GLfloat diffuse_r;
		GLfloat diffuse_g;
		GLfloat diffuse_b;

		GLfloat specular_r;
		GLfloat specular_g;
		GLfloat specular_b;

		GLfloat emissive_r;
		GLfloat emissive_g;
		GLfloat emissive_b;

		GLfloat shininess;
	};

	// Our vertex type
	typedef struct
	{
		float x,y,z;
	}vertex_type;

	// The polygon (triangle), 3 numbers that aim 3 vertices
	typedef struct
	{
		unsigned short a,b,c;
	}polygon_type;

	// The mapcoord type, 2 texture coordinates for each vertex
	typedef struct
	{
		float u,v;
	} mapcoord_type;

	// The object type
	typedef struct 
	{
		char name[20];
    
		int vertices_qty;
		int polygons_qty;

		vertex_type vertex[MAX_VERTICES]; 
		polygon_type polygon[MAX_POLYGONS];
		mapcoord_type mapcoord[MAX_VERTICES];
		int id_texture;
	} obj_type, *obj_type_ptr;

	enum OBJECT
	{
		ICOSAHEDRON,
		TEAPOT,
		FILE_OBJECT
	};

	explicit OpenGLFrame(QWidget *parent = 0);
	~OpenGLFrame();

	Light *light1;
	Light *light2;
	Light *light3;
	Material *material;
	EnvironmentMap *environmentMap;
	obj_type object;
	obj_type_ptr currentObject;

public:

    void initializeGL();
    void resizeGL( int w , int h );
    void paintGL();

	void setupMaterial( Material *currentMaterial );
	void setupLights();
	void setupEnvironmentMap();
	void setShader( SHADER s );
	void setDrawableObject( OBJECT object ); 
	void setupTransformations();
	void setupGrid();
	void drawObject();
	void drawFileObject();

	void wheelEvent ( QWheelEvent *event );
	void mousePressEvent( QMouseEvent *event );
	void mouseMoveEvent( QMouseEvent *event );

	void OpenGLFrame::loadFace(GLenum target, char *filename);
	void OpenGLFrame::updateTexgen(void);
	void OpenGLFrame::updateWrap(void);
	void OpenGLFrame::makeCubeMap(void);

	void setupNormalMappingShader( QString vertexFilename , QString fragmentFilename );
	void setupPerPixelShader( QString vertexFilename , QString fragmentFilename );
	void setupPhongShader( QString vertexFilename , QString fragmentFilename );
	void setupCustomShader1( QString vertexFilename , QString fragmentFilename );
	void setupToonShader( QString vertexFilename , QString fragmentFilename );
	void setupCustomShader2( QString vertexFilename , QString fragmentFilename );
	void refreshShader();

	GLuint LoadTexture( const char * filename, int width, int height );
	void FreeTexture( GLuint texture );
	void OpenGLFrame::makeObject();

public slots:
	void update();

private:

	QWidget *superWidget;
	Icosahedron *icosahedron;
	OBJECT CURRENT_OBJECT;

	GLfloat zoom;
	GLint previousX;
	GLint previousY;
	GLint currentX;
	GLint currentY;
	GLfloat rotateX;
	GLfloat rotateY;
	GLfloat panX;
	GLfloat panY;
	Qt::MouseButton currentButton;

	QGLShaderProgram *shaderProgram;
	GLboolean usingShaderProgram;

	GLuint texture;  
	GLuint normal_texture;
	QOpenGLContext *m_context;


	 GLuint textures[6];
     QVector<QVector3D> vertices;
     QVector<QVector2D> texCoords;

	 SHADER CURRENT_SHADER;

	 QTimer *timer;
};

#endif // OPENGLFRAME_H
