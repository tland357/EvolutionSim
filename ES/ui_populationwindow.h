/********************************************************************************
** Form generated from reading UI file 'populationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPULATIONWINDOW_H
#define UI_POPULATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PopulationWindow
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollBar *verticalScrollBar;
    QLabel *PopulationDescription;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *PopulationWindow)
    {
        if (PopulationWindow->objectName().isEmpty())
            PopulationWindow->setObjectName(QString::fromUtf8("PopulationWindow"));
        PopulationWindow->resize(800, 600);
        centralwidget = new QWidget(PopulationWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 801, 551));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 799, 549));
        verticalScrollBar = new QScrollBar(scrollAreaWidgetContents);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(780, 10, 16, 531));
        verticalScrollBar->setOrientation(Qt::Vertical);
        PopulationDescription = new QLabel(scrollAreaWidgetContents);
        PopulationDescription->setObjectName(QString::fromUtf8("PopulationDescription"));
        PopulationDescription->setGeometry(QRect(10, 10, 761, 711));
        QFont font;
        font.setPointSize(24);
        PopulationDescription->setFont(font);
        PopulationDescription->setAutoFillBackground(false);
        PopulationDescription->setFrameShadow(QFrame::Plain);
        scrollArea->setWidget(scrollAreaWidgetContents);
        PopulationWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(PopulationWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PopulationWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(PopulationWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        PopulationWindow->setMenuBar(menubar);

        retranslateUi(PopulationWindow);

        QMetaObject::connectSlotsByName(PopulationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PopulationWindow)
    {
        PopulationWindow->setWindowTitle(QApplication::translate("PopulationWindow", "MainWindow", nullptr));
        PopulationDescription->setText(QApplication::translate("PopulationWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PopulationWindow: public Ui_PopulationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPULATIONWINDOW_H
