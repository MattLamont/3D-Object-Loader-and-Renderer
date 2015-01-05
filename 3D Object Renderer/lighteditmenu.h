#ifndef LIGHTEDITMENU_H
#define LIGHTEDITMENU_H

#include <QDialog>
#include "OpenGLFrame.h"
#include "ui_LightEditMenu.h"

class LightEditMenu : public QDialog
{
	Q_OBJECT

public:
	LightEditMenu(QWidget *parent);
	~LightEditMenu();

	void setGLLight( OpenGLFrame *gl , OpenGLFrame::Light *l ,  QString lightNumber );

public slots:
	void applyLightChanges();

private:
	Ui::Light_Dialog ui;
	OpenGLFrame::Light *light;
	OpenGLFrame *openGLFrame;
};

#endif // LIGHTEDITMENU_H
