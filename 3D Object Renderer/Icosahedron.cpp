#include "Icosahedron.h"


Icosahedron::Icosahedron( SHADING_TYPE st , SUBDIVISION_COUNT sc )
{
	this->CURRENT_SHADING_TYPE = st;
	this->CURRENT_SUBDIVISION_COUNT = sc;
}

Icosahedron::Icosahedron()
{
	this->CURRENT_SHADING_TYPE = SMOOTH_SHADING;
	this->CURRENT_SUBDIVISION_COUNT = LEVEL_20;
}

void Icosahedron::setShadingType( SHADING_TYPE st )
{
	this->CURRENT_SHADING_TYPE = st;
}

void Icosahedron::setSubdivisionCount( SUBDIVISION_COUNT sc )
{
	this->CURRENT_SUBDIVISION_COUNT = sc;
}

Icosahedron::SHADING_TYPE Icosahedron::getShadingType()
{
	return this->CURRENT_SHADING_TYPE;
}

Icosahedron::SUBDIVISION_COUNT Icosahedron::getSubdivisionCount()
{
	return this->CURRENT_SUBDIVISION_COUNT;
}

void Icosahedron::draw()
{

	//draw with user chosen subdivision level
	switch( CURRENT_SUBDIVISION_COUNT )
	{
	case LEVEL_20:
		for( int i = 0 ; i < 20 ; i++ )
		{
			subdivide( &vdata[ tindices[i][0]][0] , &vdata[ tindices[i][1]][0] , &vdata[ tindices[i][2]][0] , 0 );
		}
		break;

	case LEVEL_80:
		for( int i = 0 ; i < 20 ; i++ )
		{
			subdivide( &vdata[ tindices[i][0]][0] , &vdata[ tindices[i][1]][0] , &vdata[ tindices[i][2]][0] , 1 );
		}
		break;

	case LEVEL_320:
		for( int i = 0 ; i < 20 ; i++ )
		{
			subdivide( &vdata[ tindices[i][0]][0] , &vdata[ tindices[i][1]][0] , &vdata[ tindices[i][2]][0] , 2 );
		}
		break;

	case LEVEL_1280:
		for( int i = 0 ; i < 20 ; i++ )
		{
			subdivide( &vdata[ tindices[i][0]][0] , &vdata[ tindices[i][1]][0] , &vdata[ tindices[i][2]][0] , 3 );
		}
		break;

	default:
		for( int i = 0 ; i < 20 ; i++ )
		{
			subdivide( &vdata[ tindices[i][0]][0] , &vdata[ tindices[i][1]][0] , &vdata[ tindices[i][2]][0] , 0 );
		}
		break;
	}
}




void Icosahedron::subdivide(float *v1, float *v2, float *v3, long depth)
{
	GLfloat v12[3], v23[3], v31[3];
	GLint i;

	if (depth == 0) 
	{
		drawtriangle(v1, v2, v3);
		return;
	}
	for (i = 0; i < 3; i++) {
		v12[i] = (v1[i]+v2[i])/2;
		v23[i] = (v2[i]+v3[i])/2;
		v31[i] = (v3[i]+v1[i])/2;
	}
	normalize(v12);
	normalize(v23);
	normalize(v31);
	subdivide(v1, v12, v31, depth-1);
	subdivide(v2, v23, v12, depth-1);
	subdivide(v3, v31, v23, depth-1);
	subdivide(v12, v23, v31, depth-1);
}

void Icosahedron::drawtriangle(float *v1, float *v2, float *v3)
{
	glBegin(GL_POLYGON); 
      glNormal3fv(v1); glVertex3fv(v1);    
      glNormal3fv(v2); glVertex3fv(v2);    
      glNormal3fv(v3); glVertex3fv(v3);    
	glEnd();
}

void Icosahedron::normalize(float v[3])
{
	GLfloat d = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]); 
   if (d == 0.0) 
   {
      //error("zero length vector");    
      return;
   }
   v[0] /= d; v[1] /= d; v[2] /= d; 
}
