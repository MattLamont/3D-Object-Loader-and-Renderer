#pragma once

#include <QtOpenGl/QGLWidget>


#define X .525731112119133606 
#define Z .850650808352039932

static GLfloat vdata[12][3] = {    
   {-X, 0.0, Z}, {X, 0.0, Z}, {-X, 0.0, -Z}, {X, 0.0, -Z},    
   {0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X},    
   {Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0} 
};

static GLint tindices[20][3] = { 
   {0,4,1}, {0,9,4}, {9,5,4}, {4,5,8}, {4,8,1},    
   {8,10,1}, {8,3,10}, {5,3,8}, {5,2,3}, {2,7,3},    
   {7,10,3}, {7,6,10}, {7,11,6}, {11,0,6}, {0,1,6}, 
   {6,1,10}, {9,0,11}, {9,11,2}, {9,2,5}, {7,2,11} };





class Icosahedron
{

public:
	
	enum SHADING_TYPE
	{
		FLAT_SHADING,
		SMOOTH_SHADING
	}; 

	enum SUBDIVISION_COUNT
	{
		LEVEL_20,
		LEVEL_80,
		LEVEL_320,
		LEVEL_1280
	};

	Icosahedron( SHADING_TYPE st , SUBDIVISION_COUNT sc );
	Icosahedron();

	void setShadingType( SHADING_TYPE st );
	void setSubdivisionCount( SUBDIVISION_COUNT sc );

	SHADING_TYPE getShadingType();
	SUBDIVISION_COUNT getSubdivisionCount();

	void draw();

private:

	void subdivide(float *v1, float *v2, float *v3, long depth);
	void drawtriangle(float *v1, float *v2, float *v3);
	void normalize(float v[3]);

	SHADING_TYPE CURRENT_SHADING_TYPE;
	SUBDIVISION_COUNT CURRENT_SUBDIVISION_COUNT;


	
};

