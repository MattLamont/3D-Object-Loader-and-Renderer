/*
 * ---------------- www.spacesimulator.net --------------
 *   ---- Space simulators and 3d engine tutorials ----
 *
 * Author: Damiano Vitulli
 *
 * This program is released under the BSD licence
 * By using this program you agree to licence terms on spacesimulator.net copyright page
 *
 *
 * Tutorial 4: 3d engine - 3ds models loader
 * 
 * File header: 3dsloader.h
 *  
 */



#include <qstring.h>
#include "openglframe.h"



class ObjectLoader
{
public:

	ObjectLoader( OpenGLFrame *gl );

	void setObjectFilename( QString f );

private:

	OpenGLFrame *openGLFrame;
	const char *filename;
	OpenGLFrame::obj_type_ptr currentObject;

	char Load3DS( OpenGLFrame::obj_type_ptr p_object );

};