/********************************************************************************
** Form generated from reading UI file 'MaterialEditMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALEDITMENU_H
#define UI_MATERIALEDITMENU_H

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

class Ui_Material_Dialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QRadioButton *radioButton;
    QWidget *tab_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QWidget *tab_3;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QWidget *tab_4;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QWidget *tab_5;
    QWidget *formLayoutWidget_5;
    QFormLayout *formLayout_5;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_10;
    QDoubleSpinBox *doubleSpinBox_11;
    QDoubleSpinBox *doubleSpinBox_12;
    QWidget *tab_6;
    QWidget *formLayoutWidget_6;
    QFormLayout *formLayout_6;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBox_13;

    void setupUi(QDialog *Material_Dialog)
    {
        if (Material_Dialog->objectName().isEmpty())
            Material_Dialog->setObjectName(QStringLiteral("Material_Dialog"));
        Material_Dialog->resize(435, 263);
        layoutWidget = new QWidget(Material_Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 210, 351, 33));
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

        tabWidget = new QTabWidget(Material_Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 401, 191));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        formLayoutWidget = new QWidget(tab);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(9, 9, 351, 151));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(formLayoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, radioButton);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        formLayoutWidget_2 = new QWidget(tab_2);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 10, 371, 151));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_4);

        doubleSpinBox = new QDoubleSpinBox(formLayoutWidget_2);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMaximum(1);
        doubleSpinBox->setSingleStep(0.05);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, doubleSpinBox);

        doubleSpinBox_2 = new QDoubleSpinBox(formLayoutWidget_2);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setMaximum(1);
        doubleSpinBox_2->setSingleStep(0.05);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, doubleSpinBox_2);

        doubleSpinBox_3 = new QDoubleSpinBox(formLayoutWidget_2);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setMaximum(1);
        doubleSpinBox_3->setSingleStep(0.05);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, doubleSpinBox_3);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        formLayoutWidget_3 = new QWidget(tab_3);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(10, 10, 371, 151));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(formLayoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(formLayoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_7);

        doubleSpinBox_4 = new QDoubleSpinBox(formLayoutWidget_3);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setMaximum(1);
        doubleSpinBox_4->setSingleStep(0.05);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, doubleSpinBox_4);

        doubleSpinBox_5 = new QDoubleSpinBox(formLayoutWidget_3);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setMaximum(1);
        doubleSpinBox_5->setSingleStep(0.05);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, doubleSpinBox_5);

        doubleSpinBox_6 = new QDoubleSpinBox(formLayoutWidget_3);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setMaximum(1);
        doubleSpinBox_6->setSingleStep(0.05);

        formLayout_3->setWidget(5, QFormLayout::LabelRole, doubleSpinBox_6);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        formLayoutWidget_4 = new QWidget(tab_4);
        formLayoutWidget_4->setObjectName(QStringLiteral("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(10, 10, 371, 151));
        formLayout_4 = new QFormLayout(formLayoutWidget_4);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(formLayoutWidget_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(formLayoutWidget_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_9);

        label_10 = new QLabel(formLayoutWidget_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_4->setWidget(4, QFormLayout::LabelRole, label_10);

        doubleSpinBox_7 = new QDoubleSpinBox(formLayoutWidget_4);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setMaximum(1);
        doubleSpinBox_7->setSingleStep(0.05);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, doubleSpinBox_7);

        doubleSpinBox_8 = new QDoubleSpinBox(formLayoutWidget_4);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setMaximum(1);
        doubleSpinBox_8->setSingleStep(0.05);

        formLayout_4->setWidget(3, QFormLayout::LabelRole, doubleSpinBox_8);

        doubleSpinBox_9 = new QDoubleSpinBox(formLayoutWidget_4);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        doubleSpinBox_9->setMaximum(1);
        doubleSpinBox_9->setSingleStep(0.05);

        formLayout_4->setWidget(5, QFormLayout::LabelRole, doubleSpinBox_9);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        formLayoutWidget_5 = new QWidget(tab_5);
        formLayoutWidget_5->setObjectName(QStringLiteral("formLayoutWidget_5"));
        formLayoutWidget_5->setGeometry(QRect(10, 10, 371, 151));
        formLayout_5 = new QFormLayout(formLayoutWidget_5);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(formLayoutWidget_5);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_11);

        label_12 = new QLabel(formLayoutWidget_5);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_12);

        label_13 = new QLabel(formLayoutWidget_5);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_5->setWidget(4, QFormLayout::LabelRole, label_13);

        doubleSpinBox_10 = new QDoubleSpinBox(formLayoutWidget_5);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));
        doubleSpinBox_10->setMaximum(1);
        doubleSpinBox_10->setSingleStep(0.05);

        formLayout_5->setWidget(1, QFormLayout::LabelRole, doubleSpinBox_10);

        doubleSpinBox_11 = new QDoubleSpinBox(formLayoutWidget_5);
        doubleSpinBox_11->setObjectName(QStringLiteral("doubleSpinBox_11"));
        doubleSpinBox_11->setMaximum(1);
        doubleSpinBox_11->setSingleStep(0.05);

        formLayout_5->setWidget(3, QFormLayout::LabelRole, doubleSpinBox_11);

        doubleSpinBox_12 = new QDoubleSpinBox(formLayoutWidget_5);
        doubleSpinBox_12->setObjectName(QStringLiteral("doubleSpinBox_12"));
        doubleSpinBox_12->setMaximum(1);
        doubleSpinBox_12->setSingleStep(0.05);

        formLayout_5->setWidget(5, QFormLayout::LabelRole, doubleSpinBox_12);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        formLayoutWidget_6 = new QWidget(tab_6);
        formLayoutWidget_6->setObjectName(QStringLiteral("formLayoutWidget_6"));
        formLayoutWidget_6->setGeometry(QRect(10, 10, 371, 151));
        formLayout_6 = new QFormLayout(formLayoutWidget_6);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        formLayout_6->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(formLayoutWidget_6);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_14);

        doubleSpinBox_13 = new QDoubleSpinBox(formLayoutWidget_6);
        doubleSpinBox_13->setObjectName(QStringLiteral("doubleSpinBox_13"));
        doubleSpinBox_13->setMaximum(128);
        doubleSpinBox_13->setSingleStep(10);

        formLayout_6->setWidget(1, QFormLayout::LabelRole, doubleSpinBox_13);

        tabWidget->addTab(tab_6, QString());
        layoutWidget->raise();
        tabWidget->raise();

        retranslateUi(Material_Dialog);
        QObject::connect(okButton, SIGNAL(clicked()), Material_Dialog, SLOT(applyMaterialChanges()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Material_Dialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Material_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Material_Dialog)
    {
        Material_Dialog->setWindowTitle(QApplication::translate("Material_Dialog", "Dialog", 0));
        okButton->setText(QApplication::translate("Material_Dialog", "Apply Changes", 0));
        cancelButton->setText(QApplication::translate("Material_Dialog", "Close", 0));
        radioButton->setText(QApplication::translate("Material_Dialog", "Use Default Material", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Material_Dialog", "General", 0));
        label_2->setText(QApplication::translate("Material_Dialog", "Red", 0));
        label_3->setText(QApplication::translate("Material_Dialog", "Green", 0));
        label_4->setText(QApplication::translate("Material_Dialog", "Blue", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Material_Dialog", "Ambient", 0));
        label_5->setText(QApplication::translate("Material_Dialog", "Red", 0));
        label_6->setText(QApplication::translate("Material_Dialog", "Green", 0));
        label_7->setText(QApplication::translate("Material_Dialog", "Blue", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Material_Dialog", "Diffuse", 0));
        label_8->setText(QApplication::translate("Material_Dialog", "Red", 0));
        label_9->setText(QApplication::translate("Material_Dialog", "Green", 0));
        label_10->setText(QApplication::translate("Material_Dialog", "Blue", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Material_Dialog", "Specular", 0));
        label_11->setText(QApplication::translate("Material_Dialog", "Red", 0));
        label_12->setText(QApplication::translate("Material_Dialog", "Green", 0));
        label_13->setText(QApplication::translate("Material_Dialog", "Blue", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("Material_Dialog", "Emissive", 0));
        label_14->setText(QApplication::translate("Material_Dialog", "Shininess", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("Material_Dialog", "Shininess", 0));
    } // retranslateUi

};

namespace Ui {
    class Material_Dialog: public Ui_Material_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALEDITMENU_H
