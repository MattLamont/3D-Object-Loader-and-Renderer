#ifndef MATERIALEDITMENU_H
#define MATERIALEDITMENU_H

#include <QDialog>
#include "ui_MaterialEditMenu.h"
#include "OpenGLFrame.h"

class MaterialEditMenu : public QDialog
{
	Q_OBJECT

public:
	MaterialEditMenu(QWidget *parent);
	~MaterialEditMenu();

	void setGLMaterial( OpenGLFrame *gl , OpenGLFrame::Material *m );

public slots:
	void applyMaterialChanges();


private:
	Ui::Material_Dialog ui;
	OpenGLFrame::Material *material;
	OpenGLFrame *openGLFrame;
};

#endif // MATERIALEDITMENU_H
