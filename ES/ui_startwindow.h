/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QPushButton *StartSim_BT;
    QLineEdit *SeedInput;
    QLabel *SeedLabel;
    QLabel *ForgivenessLabel;
    QLineEdit *ForgivenessInput;
    QLabel *CapacityLabel;
    QLineEdit *CapacityInput;
    QLineEdit *MutationInput;
    QLabel *MutationLabel;
    QGroupBox *EvolutionTypeGroupBox;
    QRadioButton *SimType1;
    QRadioButton *SimType2;
    QRadioButton *SimType3;
    QLabel *GenerationLabel;
    QLabel *EvolutionCounter;
    QPushButton *MultiGen_BT;
    QSlider *verticalSlider;
    QLabel *label;
    QLineEdit *CreatureObserveInput;
    QLabel *CreatureObserver;
    QPushButton *BestCreatureInfo;
    QPushButton *MedianCreatureInfo;
    QPushButton *WorstCreatureInfo;
    QLineEdit *MultiGen;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QString::fromUtf8("StartWindow"));
        StartWindow->resize(1108, 960);
        StartWindow->setMouseTracking(false);
        centralWidget = new QWidget(StartWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 1099, 931));
        StartSim_BT = new QPushButton(widget);
        StartSim_BT->setObjectName(QString::fromUtf8("StartSim_BT"));
        StartSim_BT->setGeometry(QRect(360, 410, 321, 91));
        QFont font;
        font.setPointSize(14);
        StartSim_BT->setFont(font);
        StartSim_BT->setCursor(QCursor(Qt::PointingHandCursor));
        StartSim_BT->setCheckable(false);
        SeedInput = new QLineEdit(widget);
        SeedInput->setObjectName(QString::fromUtf8("SeedInput"));
        SeedInput->setGeometry(QRect(360, 50, 321, 91));
        QFont font1;
        font1.setPointSize(24);
        SeedInput->setFont(font1);
        SeedInput->setMaxLength(12);
        SeedInput->setAlignment(Qt::AlignCenter);
        SeedLabel = new QLabel(widget);
        SeedLabel->setObjectName(QString::fromUtf8("SeedLabel"));
        SeedLabel->setGeometry(QRect(360, 20, 321, 31));
        QFont font2;
        font2.setPointSize(12);
        SeedLabel->setFont(font2);
        SeedLabel->setAlignment(Qt::AlignCenter);
        ForgivenessLabel = new QLabel(widget);
        ForgivenessLabel->setObjectName(QString::fromUtf8("ForgivenessLabel"));
        ForgivenessLabel->setGeometry(QRect(360, 140, 321, 31));
        ForgivenessLabel->setFont(font2);
        ForgivenessLabel->setAlignment(Qt::AlignCenter);
        ForgivenessInput = new QLineEdit(widget);
        ForgivenessInput->setObjectName(QString::fromUtf8("ForgivenessInput"));
        ForgivenessInput->setGeometry(QRect(360, 170, 321, 91));
        ForgivenessInput->setFont(font1);
        ForgivenessInput->setToolTipDuration(2);
        ForgivenessInput->setAlignment(Qt::AlignCenter);
        CapacityLabel = new QLabel(widget);
        CapacityLabel->setObjectName(QString::fromUtf8("CapacityLabel"));
        CapacityLabel->setGeometry(QRect(10, 260, 321, 31));
        CapacityLabel->setFont(font2);
        CapacityLabel->setAlignment(Qt::AlignCenter);
        CapacityInput = new QLineEdit(widget);
        CapacityInput->setObjectName(QString::fromUtf8("CapacityInput"));
        CapacityInput->setGeometry(QRect(10, 290, 321, 91));
        CapacityInput->setFont(font1);
        CapacityInput->setMaxLength(4);
        CapacityInput->setAlignment(Qt::AlignCenter);
        MutationInput = new QLineEdit(widget);
        MutationInput->setObjectName(QString::fromUtf8("MutationInput"));
        MutationInput->setGeometry(QRect(10, 170, 321, 91));
        MutationInput->setFont(font1);
        MutationInput->setAlignment(Qt::AlignCenter);
        MutationLabel = new QLabel(widget);
        MutationLabel->setObjectName(QString::fromUtf8("MutationLabel"));
        MutationLabel->setGeometry(QRect(10, 140, 321, 31));
        MutationLabel->setFont(font2);
        MutationLabel->setAlignment(Qt::AlignCenter);
        EvolutionTypeGroupBox = new QGroupBox(widget);
        EvolutionTypeGroupBox->setObjectName(QString::fromUtf8("EvolutionTypeGroupBox"));
        EvolutionTypeGroupBox->setGeometry(QRect(10, 10, 321, 131));
        EvolutionTypeGroupBox->setFont(font2);
        SimType1 = new QRadioButton(EvolutionTypeGroupBox);
        SimType1->setObjectName(QString::fromUtf8("SimType1"));
        SimType1->setGeometry(QRect(20, 20, 171, 41));
        QFont font3;
        font3.setPointSize(10);
        SimType1->setFont(font3);
        SimType1->setCursor(QCursor(Qt::PointingHandCursor));
        SimType1->setIconSize(QSize(20, 20));
        SimType1->setCheckable(true);
        SimType1->setChecked(true);
        SimType2 = new QRadioButton(EvolutionTypeGroupBox);
        SimType2->setObjectName(QString::fromUtf8("SimType2"));
        SimType2->setGeometry(QRect(20, 50, 311, 41));
        SimType2->setFont(font3);
        SimType2->setCursor(QCursor(Qt::PointingHandCursor));
        SimType2->setIconSize(QSize(20, 20));
        SimType2->setCheckable(true);
        SimType2->setChecked(false);
        SimType3 = new QRadioButton(EvolutionTypeGroupBox);
        SimType3->setObjectName(QString::fromUtf8("SimType3"));
        SimType3->setGeometry(QRect(20, 80, 311, 41));
        SimType3->setFont(font3);
        SimType3->setCursor(QCursor(Qt::PointingHandCursor));
        SimType3->setIconSize(QSize(20, 20));
        SimType3->setCheckable(true);
        SimType3->setChecked(false);
        GenerationLabel = new QLabel(widget);
        GenerationLabel->setObjectName(QString::fromUtf8("GenerationLabel"));
        GenerationLabel->setGeometry(QRect(710, 410, 321, 91));
        GenerationLabel->setFont(font1);
        GenerationLabel->setFrameShape(QFrame::Box);
        GenerationLabel->setFrameShadow(QFrame::Plain);
        EvolutionCounter = new QLabel(widget);
        EvolutionCounter->setObjectName(QString::fromUtf8("EvolutionCounter"));
        EvolutionCounter->setEnabled(true);
        EvolutionCounter->setGeometry(QRect(940, 410, 91, 91));
        EvolutionCounter->setFont(font1);
        EvolutionCounter->setAlignment(Qt::AlignCenter);
        MultiGen_BT = new QPushButton(widget);
        MultiGen_BT->setObjectName(QString::fromUtf8("MultiGen_BT"));
        MultiGen_BT->setGeometry(QRect(10, 410, 181, 91));
        MultiGen_BT->setFont(font);
        MultiGen_BT->setCursor(QCursor(Qt::PointingHandCursor));
        MultiGen_BT->setCheckable(false);
        verticalSlider = new QSlider(widget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(1050, 50, 41, 791));
        verticalSlider->setMinimum(-1);
        verticalSlider->setMaximum(99);
        verticalSlider->setOrientation(Qt::Vertical);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 510, 1021, 411));
        QFont font4;
        font4.setPointSize(18);
        label->setFont(font4);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(false);
        CreatureObserveInput = new QLineEdit(widget);
        CreatureObserveInput->setObjectName(QString::fromUtf8("CreatureObserveInput"));
        CreatureObserveInput->setGeometry(QRect(360, 290, 321, 91));
        CreatureObserveInput->setFont(font1);
        CreatureObserveInput->setMaxLength(8);
        CreatureObserveInput->setAlignment(Qt::AlignCenter);
        CreatureObserver = new QLabel(widget);
        CreatureObserver->setObjectName(QString::fromUtf8("CreatureObserver"));
        CreatureObserver->setGeometry(QRect(360, 260, 321, 31));
        CreatureObserver->setFont(font2);
        CreatureObserver->setAlignment(Qt::AlignCenter);
        BestCreatureInfo = new QPushButton(widget);
        BestCreatureInfo->setObjectName(QString::fromUtf8("BestCreatureInfo"));
        BestCreatureInfo->setGeometry(QRect(710, 50, 321, 91));
        BestCreatureInfo->setFont(font);
        MedianCreatureInfo = new QPushButton(widget);
        MedianCreatureInfo->setObjectName(QString::fromUtf8("MedianCreatureInfo"));
        MedianCreatureInfo->setGeometry(QRect(710, 170, 321, 91));
        MedianCreatureInfo->setFont(font);
        WorstCreatureInfo = new QPushButton(widget);
        WorstCreatureInfo->setObjectName(QString::fromUtf8("WorstCreatureInfo"));
        WorstCreatureInfo->setGeometry(QRect(710, 290, 321, 91));
        WorstCreatureInfo->setFont(font);
        WorstCreatureInfo->setCursor(QCursor(Qt::PointingHandCursor));
        MultiGen = new QLineEdit(widget);
        MultiGen->setObjectName(QString::fromUtf8("MultiGen"));
        MultiGen->setGeometry(QRect(222, 411, 111, 91));
        MultiGen->setFont(font1);
        MultiGen->setMaxLength(3);
        MultiGen->setAlignment(Qt::AlignCenter);
        StartWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StartWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1108, 26));
        StartWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(StartWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        StartWindow->setStatusBar(statusBar);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QApplication::translate("StartWindow", "Evolution Simulator", nullptr));
        StartSim_BT->setText(QApplication::translate("StartWindow", "Run Generation", nullptr));
        SeedInput->setText(QApplication::translate("StartWindow", "0", nullptr));
        SeedLabel->setText(QApplication::translate("StartWindow", "Seed", nullptr));
        ForgivenessLabel->setText(QApplication::translate("StartWindow", "Forgiveness", nullptr));
#ifndef QT_NO_TOOLTIP
        ForgivenessInput->setToolTip(QApplication::translate("StartWindow", "A measure of how forgiving natural selection is for creatures who didn't perform well.", nullptr));
#endif // QT_NO_TOOLTIP
        ForgivenessInput->setText(QApplication::translate("StartWindow", "0.5", nullptr));
        CapacityLabel->setText(QApplication::translate("StartWindow", "Capacity", nullptr));
        CapacityInput->setText(QApplication::translate("StartWindow", "100", nullptr));
#ifndef QT_NO_TOOLTIP
        MutationInput->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        MutationInput->setText(QApplication::translate("StartWindow", "0.01", nullptr));
        MutationLabel->setText(QApplication::translate("StartWindow", "Mutation Rate", nullptr));
        EvolutionTypeGroupBox->setTitle(QApplication::translate("StartWindow", "Evolution Type", nullptr));
        SimType1->setText(QApplication::translate("StartWindow", "Function Snakes", nullptr));
        SimType2->setText(QApplication::translate("StartWindow", "Function Snakes (Efficiency Based)", nullptr));
        SimType3->setText(QApplication::translate("StartWindow", "Sudoku Creatures", nullptr));
        GenerationLabel->setText(QApplication::translate("StartWindow", "Generation :", nullptr));
        EvolutionCounter->setText(QApplication::translate("StartWindow", "0", nullptr));
        MultiGen_BT->setText(QApplication::translate("StartWindow", "Run Multiple\n"
"Generations", nullptr));
        label->setText(QString());
        CreatureObserveInput->setText(QApplication::translate("StartWindow", "0", nullptr));
        CreatureObserver->setText(QApplication::translate("StartWindow", "Creature Observation", nullptr));
        BestCreatureInfo->setText(QApplication::translate("StartWindow", "Best Performer", nullptr));
        MedianCreatureInfo->setText(QApplication::translate("StartWindow", "Median Performer", nullptr));
        WorstCreatureInfo->setText(QApplication::translate("StartWindow", "Worst Performer", nullptr));
        MultiGen->setText(QApplication::translate("StartWindow", "10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
