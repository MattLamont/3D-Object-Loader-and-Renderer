/********************************************************************************
** Form generated from reading UI file 'LightEditMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTEDITMENU_H
#define UI_LIGHTEDITMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Light_Dialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QTabWidget *tabWidget;
    QWidget *General;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QRadioButton *radioButton;
    QLabel *label_2;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QWidget *tab_3;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_11;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_10;
    QDoubleSpinBox *doubleSpinBox_12;
    QLabel *label_3;
    QWidget *tab_6;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_13;
    QDoubleSpinBox *doubleSpinBox_14;
    QDoubleSpinBox *doubleSpinBox_15;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBox_19;
    QWidget *tab;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_4;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox_16;
    QDoubleSpinBox *doubleSpinBox_17;
    QDoubleSpinBox *doubleSpinBox_18;
    QWidget *tab_2;
    QWidget *formLayoutWidget_5;
    QFormLayout *formLayout_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QWidget *tab_4;
    QWidget *formLayoutWidget_6;
    QFormLayout *formLayout_6;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QWidget *tab_5;
    QWidget *formLayoutWidget_7;
    QFormLayout *formLayout_7;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;

    void setupUi(QDialog *Light_Dialog)
    {
        if (Light_Dialog->objectName().isEmpty())
            Light_Dialog->setObjectName(QStringLiteral("Light_Dialog"));
        Light_Dialog->resize(523, 271);
        Light_Dialog->setWindowTitle(QStringLiteral("Dialog"));
        layoutWidget = new QWidget(Light_Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 220, 351, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);

        tabWidget = new QTabWidget(Light_Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 495, 211));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideLeft);
        tabWidget->setDocumentMode(false);
        General = new QWidget();
        General->setObjectName(QStringLiteral("General"));
        formLayoutWidget = new QWidget(General);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 471, 151));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        radioButton = new QRadioButton(formLayoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setAutoExclusive(false);

        formLayout->setWidget(1, QFormLayout::LabelRole, radioButton);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        radioButton_2 = new QRadioButton(formLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, radioButton_2);

        radioButton_3 = new QRadioButton(formLayoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, radioButton_3);

        tabWidget->addTab(General, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        formLayoutWidget_2 = new QWidget(tab_3);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 10, 471, 161));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        doubleSpinBox_11 = new QDoubleSpinBox(formLayoutWidget_2);
        doubleSpinBox_11->setObjectName(QStringLiteral("doubleSpinBox_11"));
        doubleSpinBox_11->setMinimum(-100);
        doubleSpinBox_11->setMaximum(100);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, doubleSpinBox_11);

        label_5 = new QLabel(formLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_5);

        doubleSpinBox_10 = new QDoubleSpinBox(formLayoutWidget_2);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));
        doubleSpinBox_10->setMinimum(-100);
        doubleSpinBox_10->setMaximum(100);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, doubleSpinBox_10);

        doubleSpinBox_12 = new QDoubleSpinBox(formLayoutWidget_2);
        doubleSpinBox_12->setObjectName(QStringLiteral("doubleSpinBox_12"));
        doubleSpinBox_12->setMinimum(-100);
        doubleSpinBox_12->setMaximum(100);

        formLayout_2->setWidget(6, QFormLayout::LabelRole, doubleSpinBox_12);

        label_3 = new QLabel(formLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_3);

        tabWidget->addTab(tab_3, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        formLayoutWidget_3 = new QWidget(tab_6);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(10, 10, 491, 176));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(formLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(formLayoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(formLayoutWidget_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_8);

        doubleSpinBox_13 = new QDoubleSpinBox(formLayoutWidget_3);
        doubleSpinBox_13->setObjectName(QStringLiteral("doubleSpinBox_13"));
        doubleSpinBox_13->setMinimum(-100);
        doubleSpinBox_13->setMaximum(100);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, doubleSpinBox_13);

        doubleSpinBox_14 = new QDoubleSpinBox(formLayoutWidget_3);
        doubleSpinBox_14->setObjectName(QStringLiteral("doubleSpinBox_14"));
        doubleSpinBox_14->setMinimum(-100);
        doubleSpinBox_14->setMaximum(100);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, doubleSpinBox_14);

        doubleSpinBox_15 = new QDoubleSpinBox(formLayoutWidget_3);
        doubleSpinBox_15->setObjectName(QStringLiteral("doubleSpinBox_15"));
        doubleSpinBox_15->setMinimum(-100);
        doubleSpinBox_15->setMaximum(100);

        formLayout_3->setWidget(5, QFormLayout::LabelRole, doubleSpinBox_15);

        label_21 = new QLabel(formLayoutWidget_3);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_21);

        doubleSpinBox_19 = new QDoubleSpinBox(formLayoutWidget_3);
        doubleSpinBox_19->setObjectName(QStringLiteral("doubleSpinBox_19"));
        doubleSpinBox_19->setMaximum(90);
        doubleSpinBox_19->setSingleStep(5);

        formLayout_3->setWidget(7, QFormLayout::LabelRole, doubleSpinBox_19);

        tabWidget->addTab(tab_6, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        formLayoutWidget_4 = new QWidget(tab);
        formLayoutWidget_4->setObjectName(QStringLiteral("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(19, 19, 451, 141));
        formLayout_4 = new QFormLayout(formLayoutWidget_4);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(formLayoutWidget_4);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_18);

        label_19 = new QLabel(formLayoutWidget_4);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_19);

        label_20 = new QLabel(formLayoutWidget_4);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout_4->setWidget(4, QFormLayout::LabelRole, label_20);

        doubleSpinBox_16 = new QDoubleSpinBox(formLayoutWidget_4);
        doubleSpinBox_16->setObjectName(QStringLiteral("doubleSpinBox_16"));
        doubleSpinBox_16->setMinimum(1);
        doubleSpinBox_16->setSingleStep(0.1);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, doubleSpinBox_16);

        doubleSpinBox_17 = new QDoubleSpinBox(formLayoutWidget_4);
        doubleSpinBox_17->setObjectName(QStringLiteral("doubleSpinBox_17"));
        doubleSpinBox_17->setSingleStep(0.1);

        formLayout_4->setWidget(3, QFormLayout::LabelRole, doubleSpinBox_17);

        doubleSpinBox_18 = new QDoubleSpinBox(formLayoutWidget_4);
        doubleSpinBox_18->setObjectName(QStringLiteral("doubleSpinBox_18"));
        doubleSpinBox_18->setSingleStep(0.1);

        formLayout_4->setWidget(5, QFormLayout::LabelRole, doubleSpinBox_18);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        formLayoutWidget_5 = new QWidget(tab_2);
        formLayoutWidget_5->setObjectName(QStringLiteral("formLayoutWidget_5"));
        formLayoutWidget_5->setGeometry(QRect(19, 19, 451, 151));
        formLayout_5 = new QFormLayout(formLayoutWidget_5);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(formLayoutWidget_5);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_9);

        label_10 = new QLabel(formLayoutWidget_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_10);

        label_11 = new QLabel(formLayoutWidget_5);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_5->setWidget(4, QFormLayout::LabelRole, label_11);

        doubleSpinBox = new QDoubleSpinBox(formLayoutWidget_5);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMaximum(1);
        doubleSpinBox->setSingleStep(0.05);

        formLayout_5->setWidget(1, QFormLayout::LabelRole, doubleSpinBox);

        doubleSpinBox_2 = new QDoubleSpinBox(formLayoutWidget_5);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setMaximum(1);
        doubleSpinBox_2->setSingleStep(0.05);

        formLayout_5->setWidget(3, QFormLayout::LabelRole, doubleSpinBox_2);

        doubleSpinBox_3 = new QDoubleSpinBox(formLayoutWidget_5);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setMaximum(1);
        doubleSpinBox_3->setSingleStep(0.05);

        formLayout_5->setWidget(5, QFormLayout::LabelRole, doubleSpinBox_3);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        formLayoutWidget_6 = new QWidget(tab_4);
        formLayoutWidget_6->setObjectName(QStringLiteral("formLayoutWidget_6"));
        formLayoutWidget_6->setGeometry(QRect(20, 10, 451, 151));
        formLayout_6 = new QFormLayout(formLayoutWidget_6);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        formLayout_6->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(formLayoutWidget_6);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_12);

        label_13 = new QLabel(formLayoutWidget_6);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_6->setWidget(2, QFormLayout::LabelRole, label_13);

        label_14 = new QLabel(formLayoutWidget_6);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_6->setWidget(4, QFormLayout::LabelRole, label_14);

        doubleSpinBox_4 = new QDoubleSpinBox(formLayoutWidget_6);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setMaximum(1);
        doubleSpinBox_4->setSingleStep(0.05);

        formLayout_6->setWidget(1, QFormLayout::LabelRole, doubleSpinBox_4);

        doubleSpinBox_5 = new QDoubleSpinBox(formLayoutWidget_6);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setMaximum(1);
        doubleSpinBox_5->setSingleStep(0.05);

        formLayout_6->setWidget(3, QFormLayout::LabelRole, doubleSpinBox_5);

        doubleSpinBox_6 = new QDoubleSpinBox(formLayoutWidget_6);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setMaximum(1);
        doubleSpinBox_6->setSingleStep(0.05);

        formLayout_6->setWidget(5, QFormLayout::LabelRole, doubleSpinBox_6);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        formLayoutWidget_7 = new QWidget(tab_5);
        formLayoutWidget_7->setObjectName(QStringLiteral("formLayoutWidget_7"));
        formLayoutWidget_7->setGeometry(QRect(20, 20, 441, 161));
        formLayout_7 = new QFormLayout(formLayoutWidget_7);
        formLayout_7->setObjectName(QStringLiteral("formLayout_7"));
        formLayout_7->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(formLayoutWidget_7);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_15);

        label_16 = new QLabel(formLayoutWidget_7);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_7->setWidget(2, QFormLayout::LabelRole, label_16);

        label_17 = new QLabel(formLayoutWidget_7);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_7->setWidget(4, QFormLayout::LabelRole, label_17);

        doubleSpinBox_7 = new QDoubleSpinBox(formLayoutWidget_7);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setMaximum(1);
        doubleSpinBox_7->setSingleStep(0.05);

        formLayout_7->setWidget(1, QFormLayout::LabelRole, doubleSpinBox_7);

        doubleSpinBox_8 = new QDoubleSpinBox(formLayoutWidget_7);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setMaximum(1);

        formLayout_7->setWidget(3, QFormLayout::LabelRole, doubleSpinBox_8);

        doubleSpinBox_9 = new QDoubleSpinBox(formLayoutWidget_7);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        doubleSpinBox_9->setMaximum(1);

        formLayout_7->setWidget(5, QFormLayout::LabelRole, doubleSpinBox_9);

        tabWidget->addTab(tab_5, QString());

        retranslateUi(Light_Dialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), Light_Dialog, SLOT(reject()));
        QObject::connect(okButton, SIGNAL(clicked()), Light_Dialog, SLOT(applyLightChanges()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Light_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Light_Dialog)
    {
        okButton->setText(QApplication::translate("Light_Dialog", "Apply Changes", 0));
        cancelButton->setText(QApplication::translate("Light_Dialog", "Close", 0));
        label->setText(QApplication::translate("Light_Dialog", "Active", 0));
        radioButton->setText(QApplication::translate("Light_Dialog", "Enabled?", 0));
        label_2->setText(QApplication::translate("Light_Dialog", "Light Type", 0));
        radioButton_2->setText(QApplication::translate("Light_Dialog", "Point Light", 0));
        radioButton_3->setText(QApplication::translate("Light_Dialog", "Spot Light", 0));
        tabWidget->setTabText(tabWidget->indexOf(General), QApplication::translate("Light_Dialog", "General", 0));
        label_4->setText(QApplication::translate("Light_Dialog", "Y Position", 0));
        label_5->setText(QApplication::translate("Light_Dialog", "Z Position", 0));
        label_3->setText(QApplication::translate("Light_Dialog", "X Position", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Light_Dialog", "Position", 0));
        label_6->setText(QApplication::translate("Light_Dialog", "X Direction", 0));
        label_7->setText(QApplication::translate("Light_Dialog", "Y Direction", 0));
        label_8->setText(QApplication::translate("Light_Dialog", "Z Direction", 0));
        label_21->setText(QApplication::translate("Light_Dialog", "Spotlight Cutoff (Degrees)", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("Light_Dialog", "Direction", 0));
        label_18->setText(QApplication::translate("Light_Dialog", "Constant Coefficient ", 0));
        label_19->setText(QApplication::translate("Light_Dialog", "Linear Coefficient", 0));
        label_20->setText(QApplication::translate("Light_Dialog", "Quadratic Coefficient", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Light_Dialog", "Attenuation", 0));
        label_9->setText(QApplication::translate("Light_Dialog", "Red", 0));
        label_10->setText(QApplication::translate("Light_Dialog", "Green", 0));
        label_11->setText(QApplication::translate("Light_Dialog", "Blue", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Light_Dialog", "Ambient", 0));
        label_12->setText(QApplication::translate("Light_Dialog", "Red", 0));
        label_13->setText(QApplication::translate("Light_Dialog", "Green", 0));
        label_14->setText(QApplication::translate("Light_Dialog", "Blue", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Light_Dialog", "Diffuse", 0));
        label_15->setText(QApplication::translate("Light_Dialog", "Red", 0));
        label_16->setText(QApplication::translate("Light_Dialog", "Green", 0));
        label_17->setText(QApplication::translate("Light_Dialog", "Blue", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("Light_Dialog", "Specular", 0));
        Q_UNUSED(Light_Dialog);
    } // retranslateUi

};

namespace Ui {
    class Light_Dialog: public Ui_Light_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTEDITMENU_H
