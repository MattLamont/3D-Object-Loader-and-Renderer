#include "environmentmapeditmenu.h"


EnvironmentMapEditMenu::EnvironmentMapEditMenu(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi( this );

	//connect( ui.okButton , SIGNAL( triggered() ) , this , SLOT( applyChanges() ) );

	this->topImage = NULL;
	this->bottomImage = NULL;
	this->leftImage = NULL;
	this->rightImage = NULL;
	this->backImage = NULL;
	this->frontImage = NULL;
}

EnvironmentMapEditMenu::~EnvironmentMapEditMenu()
{

}


void EnvironmentMapEditMenu::setGLEnvironmentMap( OpenGLFrame *gl , OpenGLFrame::EnvironmentMap *em )
{
	openGLFrame = gl;
	environmentMap = em;
}

void EnvironmentMapEditMenu::applyChanges()
{
	QString filename;

	filename = ui.lineEdit->text();
	this->openFile( TOP_FACE , filename );

	filename = ui.lineEdit_2->text();
	this->openFile( BOTTOM_FACE , filename );

	filename = ui.lineEdit_3->text();
	this->openFile( LEFT_FACE , filename );

	filename = ui.lineEdit_4->text();
	this->openFile( RIGHT_FACE , filename );

	filename = ui.lineEdit_5->text();
	this->openFile( BACK_FACE , filename );

	filename = ui.lineEdit_6->text();
	this->openFile( FRONT_FACE , filename );

	environmentMap->enabled = ui.checkBox->isChecked();

	environmentMap->topFace = this->topImage;
	environmentMap->bottomFace = this->bottomImage;
	environmentMap->leftFace = this->leftImage;
	environmentMap->rightFace = this->rightImage;
	environmentMap->backFace = this->backImage;
	environmentMap->frontFace = this->frontImage;

	openGLFrame->updateGL();
}

bool EnvironmentMapEditMenu::openFile( FACE face , QString s )
{
	FILE *file;
	
	std::string filename_s = s.toStdString();
	const char* filename = filename_s.c_str();

	file = fopen( filename , "rb");

	if( file == NULL ) 
	{
		return false;
	}

	switch( face )
	{
	case TOP_FACE:
		topImage = gliReadTGA( file, filename );
		break;

	case BOTTOM_FACE:
		bottomImage = gliReadTGA( file, filename );
		break;

	case LEFT_FACE:
		leftImage = gliReadTGA( file, filename );
		break;

	case RIGHT_FACE:
		rightImage = gliReadTGA( file, filename );
		break;

	case FRONT_FACE:
		frontImage = gliReadTGA( file, filename );
		break;

	case BACK_FACE:
		backImage = gliReadTGA( file, filename );
		break;
	}

	fclose( file );

	return true;
}
