#include "programmainwindow.h"
#include <QtGui>

ProgramMainWindow::ProgramMainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	openGLFrame = ui.OpenGlFrame;
	
	createActions();
	createMenus();

	lightMenu = new LightEditMenu( this );
	materialMenu = new MaterialEditMenu( this );
	environmentMapMenu = new EnvironmentMapEditMenu( this );
	objectLoader = new ObjectLoader( openGLFrame );
}

ProgramMainWindow::~ProgramMainWindow()
{
	delete lightMenu;
	delete materialMenu;
	delete exitAction;
	delete openAction;
	delete openIcosahedronAction;
	delete openTeapotAction;
	delete infoAction;
	delete shader1Action;
	delete shader2Action;
	delete shader3Action;
	delete shader4Action;
	delete shader5Action;
	delete shader6Action;
	delete shader7Action;
	delete shader8Action;
	delete light1Action;
	delete light2Action;
	delete light3Action;
	delete materialEditAction;
	delete environmentMapMenu;
	delete environmentMapEditAction;
	delete objectLoader;
}

void ProgramMainWindow::createActions()
{
	exitAction = new QAction( tr("Exit"), this );
	exitAction->setShortcut( QKeySequence::Close );
	connect( exitAction , SIGNAL(triggered()) , this , SLOT(fExit()) );

	openAction = new QAction( tr("Open" ), this );
	openAction->setShortcut( QKeySequence::Open );
	connect( openAction , SIGNAL( triggered() ) , this , SLOT( fOpen() ) );

	openIcosahedronAction = new QAction( tr("Icosahedron" ), this );
	connect( openIcosahedronAction , SIGNAL( triggered() ) , this , SLOT( openIcosahedron() ) ); 

	openTeapotAction = new QAction( tr("Teapot" ), this );
	connect( openTeapotAction , SIGNAL( triggered() ) , this , SLOT( openTeapot() ) );

	infoAction = new QAction( tr("Info") , this );
	infoAction->setShortcut( QKeySequence::HelpContents);
	connect( infoAction , SIGNAL(triggered()) , this , SLOT(iInfo() ) );

	shader1Action = new QAction( tr("Flat Shading" ) , this );
	connect( shader1Action , SIGNAL( triggered() ) , this , SLOT( sShader1() ) );

	shader2Action = new QAction( tr("Smooth Shading" ) , this );
	connect( shader2Action , SIGNAL( triggered() ) , this , SLOT( sShader2() ) );

	shader3Action = new QAction( tr("Normal Mapping" ) , this );
	connect( shader3Action , SIGNAL( triggered() ) , this , SLOT( sShader3() ) );

	shader4Action = new QAction( tr("Per Pixel Shading" ) , this );
	connect( shader4Action , SIGNAL( triggered() ) , this , SLOT( sShader4() ) );

	shader5Action = new QAction( tr("Phong Shading" ) , this );
	connect( shader5Action , SIGNAL( triggered() ) , this , SLOT( sShader5() ) );

	shader6Action = new QAction( tr("Custom Shader 1" ) , this );
	connect( shader6Action , SIGNAL( triggered() ) , this , SLOT( sShader6() ) );

	shader7Action = new QAction( tr("Toon Shader" ) , this );
	connect( shader7Action , SIGNAL( triggered() ) , this , SLOT( sShader7() ) );

	shader8Action = new QAction( tr("Custom Shader 2" ) , this );
	connect( shader8Action , SIGNAL( triggered() ) , this , SLOT( sShader8() ) );

	light1Action = new QAction( tr ("Light 1" ) , this );
	connect( light1Action , SIGNAL( triggered() ) , this , SLOT ( lLight1() ) );

	light2Action = new QAction( tr ("Light 2" ) , this );
	connect( light2Action , SIGNAL( triggered() ) , this , SLOT ( lLight2() ) );

	light3Action = new QAction( tr ("Light 3" ) , this );
	connect( light3Action , SIGNAL( triggered() ) , this , SLOT ( lLight3() ) );

	materialEditAction = new QAction( tr ( "Edit" ) , this );
	connect( materialEditAction , SIGNAL( triggered() ) , this , SLOT( materialEdit() ) );

	environmentMapEditAction = new QAction( tr ( "Edit" ) , this );
	connect( environmentMapEditAction , SIGNAL( triggered() ) , this , SLOT( environmentMapEdit() ) );
}

void ProgramMainWindow::createMenus()
{
	file = menuBar()->addMenu( tr ( "File" ) );
	file->addAction( openAction );
	file->addAction( openIcosahedronAction );
	file->addAction( openTeapotAction );
	file->addAction( exitAction );

	shader = menuBar()->addMenu( tr ("Shaders" ) );
	shader->addAction( shader1Action );
	shader->addAction( shader2Action );
	shader->addAction( shader3Action );
	shader->addAction( shader4Action );
	shader->addAction( shader5Action );
	shader->addAction( shader6Action );
	shader->addAction( shader7Action );
	shader->addAction( shader8Action );

	lights = menuBar()->addMenu( tr( "Lights" ) );
	lights->addAction( light1Action );
	lights->addAction( light2Action );
	lights->addAction( light3Action );

	material = menuBar()->addMenu( tr ("Material" ));
	material->addAction( materialEditAction );

	environmentMap = menuBar()->addMenu( tr ( "Environment Map" ));
	environmentMap->addAction( environmentMapEditAction );

	about = menuBar()->addMenu( tr ("About" ) );
	about->addAction( infoAction );
}

void ProgramMainWindow::fExit()
{
	ProgramMainWindow::close();
}

void ProgramMainWindow::iInfo()
{
	msgBox = new QMessageBox( this );
	msgBox->setText( tr ("This a 3D Object Renderer utilizing OpenGL" )); 
	msgBox->setIcon( QMessageBox::Question );
	msgBox->setStandardButtons( QMessageBox::Ok );
	msgBox->exec();
}

void ProgramMainWindow::fOpen()
{
	QString filename = QFileDialog::getOpenFileName(this,
		tr("Open 3DS File"), "./", tr("3DS Files (*.3ds)"));

	objectLoader->setObjectFilename( filename );
}

void ProgramMainWindow::sShader1()
{
	openGLFrame->setShader( OpenGLFrame::SHADER::FLAT_SHADER );
}

void ProgramMainWindow::sShader2()
{
	openGLFrame->setShader( OpenGLFrame::SHADER::SMOOTH_SHADER );
}

void ProgramMainWindow::sShader3()
{
	openGLFrame->setShader( OpenGLFrame::SHADER::NORMAL_MAPPING );
}

void ProgramMainWindow::sShader4()
{
	openGLFrame->setShader( OpenGLFrame::SHADER::PER_PIXEL_SHADING );
}

void ProgramMainWindow::sShader5()
{
	openGLFrame->setShader( OpenGLFrame::SHADER::PHONG_SHADING );
}

void ProgramMainWindow::sShader6()
{
	openGLFrame->setShader( OpenGLFrame::SHADER::CUSTOM_SHADER1 );
}

void ProgramMainWindow::sShader7()
{
	openGLFrame->setShader( OpenGLFrame::SHADER::TOON_SHADER );
}

void ProgramMainWindow::sShader8()
{
	openGLFrame->setShader( OpenGLFrame::SHADER::CUSTOM_SHADER2 );
}

void ProgramMainWindow::lLight1()
{
	lightMenu->setGLLight( openGLFrame , openGLFrame->light1 , "1" );
	lightMenu->show();
}

void ProgramMainWindow::lLight2()
{
	lightMenu->setGLLight( openGLFrame , openGLFrame->light2 , "2" );
	lightMenu->show();
}

void ProgramMainWindow::lLight3()
{
	lightMenu->setGLLight( openGLFrame , openGLFrame->light3 , "3" );
	lightMenu->show();
}

void ProgramMainWindow::materialEdit()
{
	materialMenu->setGLMaterial( openGLFrame , openGLFrame->material );
	materialMenu->show();
}

void ProgramMainWindow::environmentMapEdit()
{
	environmentMapMenu->setGLEnvironmentMap( openGLFrame , openGLFrame->environmentMap );
	environmentMapMenu->show();
}

void ProgramMainWindow::openIcosahedron()
{
	openGLFrame->setDrawableObject( OpenGLFrame::OBJECT::ICOSAHEDRON );
	openGLFrame->updateGL();
}

void ProgramMainWindow::openTeapot()
{
	openGLFrame->setDrawableObject( OpenGLFrame::OBJECT::TEAPOT );
	openGLFrame->updateGL();
}

