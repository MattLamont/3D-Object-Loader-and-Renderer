#ifndef EnvironmentMapEditMenu_H
#define EnvironmentMapEditMenu_H

#include <QDialog>
#include <assert.h>
#include <string>
//#include "GL/glew.h"
#include "GL/glut.h"
#include "openglframe.h"
#include "ui_EnvironmentMapEditMenu.h"
extern "C" 
{
	#include "tga.h"
}


class EnvironmentMapEditMenu : public QDialog
{
	Q_OBJECT

public:

	enum FACE
	{
		TOP_FACE,
		BOTTOM_FACE,
		RIGHT_FACE,
		LEFT_FACE,
		FRONT_FACE,
		BACK_FACE
	};

	EnvironmentMapEditMenu(QWidget *parent);
	~EnvironmentMapEditMenu();

	void setGLEnvironmentMap( OpenGLFrame *gl , OpenGLFrame::EnvironmentMap *em );

public slots:

	void applyChanges();

private:

	bool openFile( FACE face , QString filename );
	
private:

	Ui::Dialog ui;
	QPushButton *applyChangesButton;

	OpenGLFrame *openGLFrame;
	OpenGLFrame::EnvironmentMap *environmentMap;

	gliGenericImage *topImage;
	gliGenericImage *bottomImage;
	gliGenericImage *leftImage;
	gliGenericImage *rightImage;
	gliGenericImage *backImage;
	gliGenericImage *frontImage;
	
};

#endif // EnvironmentMapEditMenu_H
