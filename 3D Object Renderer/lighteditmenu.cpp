#include "lighteditmenu.h"

LightEditMenu::LightEditMenu(QWidget *parent)
	: QDialog(parent) 
{
	ui.setupUi( this );

}

LightEditMenu::~LightEditMenu()
{

}

void LightEditMenu::setGLLight( OpenGLFrame *gl , OpenGLFrame::Light *l , QString lightNumber )
{
	light = l;
	openGLFrame = gl;

	QString title = "Light ";
	title += lightNumber;
	title += " Properties";
	this->setWindowTitle( title );

	switch( light->enabled )
	{
	case true:
		ui.radioButton->setChecked( true );
		break;

	case false:
		ui.radioButton->setChecked( false );
		break;

	}

	ui.doubleSpinBox->setValue( light->ambient_r );
	ui.doubleSpinBox_2->setValue( light->ambient_g );
	ui.doubleSpinBox_3->setValue( light->ambient_b );

	ui.doubleSpinBox_4->setValue( light->diffuse_r );
	ui.doubleSpinBox_5->setValue( light->diffuse_g );
	ui.doubleSpinBox_6->setValue( light->diffuse_b );

	ui.doubleSpinBox_7->setValue( light->specular_r );
	ui.doubleSpinBox_8->setValue( light->specular_g );
	ui.doubleSpinBox_9->setValue( light->specular_b );

	ui.doubleSpinBox_10->setValue( light->position_x );
	ui.doubleSpinBox_11->setValue( light->position_y );
	ui.doubleSpinBox_12->setValue( light->position_z );

	ui.doubleSpinBox_13->setValue( light->direction_x );
	ui.doubleSpinBox_14->setValue( light->direction_y );
	ui.doubleSpinBox_15->setValue( light->direction_z );

	ui.doubleSpinBox_16->setValue( light->attenuation_constant );
	ui.doubleSpinBox_17->setValue( light->attenuation_linear );
	ui.doubleSpinBox_18->setValue( light->attenuation_quadratic );

	ui.doubleSpinBox_19->setValue( light->spotlight_cutoff );

	switch( light->light_type )
	{
	case OpenGLFrame::Light::POINT_LIGHT:
		ui.radioButton_2->setChecked( true );
		break;

	case OpenGLFrame::Light::SPOT_LIGHT:
		ui.radioButton_3->setChecked( true );
		break;

	default:
		ui.radioButton_2->setChecked( true );
		break;
	}
	
}

void LightEditMenu::applyLightChanges()
{
	if( ui.radioButton->isChecked() )
	{
		light->enabled = true;
	}
	else
	{
		light->enabled = false;
	}

	light->ambient_r = ui.doubleSpinBox->value();
	light->ambient_g = ui.doubleSpinBox_2->value();
	light->ambient_b = ui.doubleSpinBox_3->value();

	light->diffuse_r = ui.doubleSpinBox_4->value();
	light->diffuse_g = ui.doubleSpinBox_5->value();
	light->diffuse_b = ui.doubleSpinBox_6->value();

	light->specular_r = ui.doubleSpinBox_7->value();
	light->specular_g = ui.doubleSpinBox_8->value();
	light->specular_b = ui.doubleSpinBox_9->value();

	light->position_x = ui.doubleSpinBox_10->value();
	light->position_y = ui.doubleSpinBox_11->value();
	light->position_z = ui.doubleSpinBox_12->value();

	light->direction_x = ui.doubleSpinBox_13->value();
	light->direction_y = ui.doubleSpinBox_14->value();
	light->direction_z = ui.doubleSpinBox_15->value();

	light->attenuation_constant = ui.doubleSpinBox_16->value();
	light->attenuation_linear = ui.doubleSpinBox_17->value();
	light->attenuation_quadratic = ui.doubleSpinBox_18->value();

	light->spotlight_cutoff = ui.doubleSpinBox_19->value();

	if( ui.radioButton_2->isChecked() )
	{
		light->light_type = OpenGLFrame::Light::POINT_LIGHT;
	}
	else
	{
		light->light_type = OpenGLFrame::Light::SPOT_LIGHT;
	}

	openGLFrame->updateGL();
	
}


