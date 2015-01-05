#ifndef PROGRAMMAINWINDOW_H
#define PROGRAMMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_programmainwindow.h"
#include "lighteditmenu.h"
#include "materialeditmenu.h"
#include "openglframe.h"
#include "environmentmapeditmenu.h"
#include <QMessageBox>
#include <qfiledialog.h>
#include "ObjectLoader.h"

class QAction;

class ProgramMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	ProgramMainWindow(QWidget *parent = 0);
	~ProgramMainWindow();

private slots:
	void fExit();
	void iInfo();
	void fOpen();
	void openIcosahedron();
	void openTeapot();
	void sShader1();
	void sShader2();
	void sShader3();
	void sShader4();
	void sShader5();
	void sShader6();
	void sShader7();
	void sShader8();
	void lLight1();
	void lLight2();
	void lLight3();
	void materialEdit();
	void environmentMapEdit();

private:
	void createMenus();
	void createActions();

	QAction *exitAction;
	QAction *infoAction;
	QAction *openAction;
	QAction *openIcosahedronAction;
	QAction *openTeapotAction;
	QAction *shader1Action;
	QAction *shader2Action;
	QAction *shader3Action;
	QAction *shader4Action;
	QAction *shader5Action;
	QAction *shader6Action;
	QAction *shader7Action;
	QAction *shader8Action;
	QAction *light1Action;
	QAction *light2Action;
	QAction *light3Action;
	QAction *materialEditAction;
	QAction *environmentMapEditAction;

	QMenu *file;
	QMenu *about;
	QMenu *shader;
	QMenu *lights;
	QMenu *material;
	QMenu *environmentMap;
	QMessageBox *msgBox;
	QFileDialog *openFileDialog;


	Ui::ProgramMainWindowClass ui;
	OpenGLFrame *openGLFrame;
	LightEditMenu *lightMenu;
	MaterialEditMenu *materialMenu;
	EnvironmentMapEditMenu *environmentMapMenu;
	ObjectLoader *objectLoader;
};

#endif // PROGRAMMAINWINDOW_H
