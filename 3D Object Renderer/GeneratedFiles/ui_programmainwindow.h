/********************************************************************************
** Form generated from reading UI file 'programmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMMAINWINDOW_H
#define UI_PROGRAMMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "openglframe.h"

QT_BEGIN_NAMESPACE

class Ui_ProgramMainWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    OpenGLFrame *OpenGlFrame;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *ProgramMainWindowClass)
    {
        if (ProgramMainWindowClass->objectName().isEmpty())
            ProgramMainWindowClass->setObjectName(QStringLiteral("ProgramMainWindowClass"));
        ProgramMainWindowClass->resize(605, 629);
        centralWidget = new QWidget(ProgramMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        OpenGlFrame = new OpenGLFrame(centralWidget);
        OpenGlFrame->setObjectName(QStringLiteral("OpenGlFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OpenGlFrame->sizePolicy().hasHeightForWidth());
        OpenGlFrame->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(OpenGlFrame);

        ProgramMainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProgramMainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 605, 21));
        ProgramMainWindowClass->setMenuBar(menuBar);

        retranslateUi(ProgramMainWindowClass);

        QMetaObject::connectSlotsByName(ProgramMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProgramMainWindowClass)
    {
        ProgramMainWindowClass->setWindowTitle(QApplication::translate("ProgramMainWindowClass", "3D Object Renderer", 0));
    } // retranslateUi

};

namespace Ui {
    class ProgramMainWindowClass: public Ui_ProgramMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMMAINWINDOW_H
