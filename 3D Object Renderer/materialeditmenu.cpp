#include "materialeditmenu.h"

MaterialEditMenu::MaterialEditMenu(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi( this );
}

MaterialEditMenu::~MaterialEditMenu()
{
	
}

void MaterialEditMenu::setGLMaterial( OpenGLFrame *gl , OpenGLFrame::Material *m )
{
	QString title = "Material Properties";
	this->setWindowTitle( title );

	material = m;
	openGLFrame = gl;

	switch( material->useDefault )
	{

	case true:
		ui.radioButton->setChecked( true );
		break;

	case false:
		ui.radioButton->setChecked( false );
		break;

	default:
		ui.radioButton->setChecked( false );
		break;

	}

	ui.doubleSpinBox->setValue( material->ambient_r );
	ui.doubleSpinBox_2->setValue( material->ambient_g );
	ui.doubleSpinBox_3->setValue( material->ambient_b );

	ui.doubleSpinBox_4->setValue( material->diffuse_r );
	ui.doubleSpinBox_5->setValue( material->diffuse_g );
	ui.doubleSpinBox_6->setValue( material->diffuse_b );

	ui.doubleSpinBox_7->setValue( material->specular_r );
	ui.doubleSpinBox_8->setValue( material->specular_g );
	ui.doubleSpinBox_9->setValue( material->specular_b );

	ui.doubleSpinBox_10->setValue( material->emissive_r );
	ui.doubleSpinBox_11->setValue( material->emissive_g );
	ui.doubleSpinBox_12->setValue( material->emissive_b );

	ui.doubleSpinBox_13->setValue( material->shininess );
}

void MaterialEditMenu::applyMaterialChanges()
{
	if( ui.radioButton->isChecked() )
	{
		material->useDefault = true;
	}
	else
	{
		material->useDefault = false;
	}

	material->ambient_r = ui.doubleSpinBox->value();
	material->ambient_g = ui.doubleSpinBox_2->value();
	material->ambient_b = ui.doubleSpinBox_3->value();

	material->diffuse_r = ui.doubleSpinBox_4->value();
	material->diffuse_g = ui.doubleSpinBox_5->value();
	material->diffuse_b = ui.doubleSpinBox_6->value();

	material->specular_r = ui.doubleSpinBox_7->value();
	material->specular_g = ui.doubleSpinBox_8->value();
	material->specular_b = ui.doubleSpinBox_9->value();

	material->emissive_r = ui.doubleSpinBox_10->value();
	material->emissive_g = ui.doubleSpinBox_11->value();
	material->emissive_b = ui.doubleSpinBox_12->value();

	material->shininess = ui.doubleSpinBox_13->value();

	openGLFrame->updateGL();
}
