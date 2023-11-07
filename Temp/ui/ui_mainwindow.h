/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ctopenglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    ctOpenglWidget *openGLWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_Url;
    QRadioButton *radioButton_TCP;
    QRadioButton *radioButton_UDP;
    QPushButton *btn_play;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_File;
    QPushButton *btn_open;
    QPushButton *btn_play2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btn_stop;
    QPushButton *btn_record;
    QPushButton *btn_stop_record;
    QPushButton *btn_snapshot;
    QPushButton *btn_open_audio;
    QPushButton *btn_close_audio;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 573);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        openGLWidget = new ctOpenglWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setMinimumSize(QSize(0, 360));

        verticalLayout_3->addWidget(openGLWidget);


        verticalLayout_2->addLayout(verticalLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_Url = new QLineEdit(centralWidget);
        lineEdit_Url->setObjectName(QStringLiteral("lineEdit_Url"));

        horizontalLayout_3->addWidget(lineEdit_Url);

        radioButton_TCP = new QRadioButton(centralWidget);
        radioButton_TCP->setObjectName(QStringLiteral("radioButton_TCP"));

        horizontalLayout_3->addWidget(radioButton_TCP);

        radioButton_UDP = new QRadioButton(centralWidget);
        radioButton_UDP->setObjectName(QStringLiteral("radioButton_UDP"));

        horizontalLayout_3->addWidget(radioButton_UDP);

        btn_play = new QPushButton(centralWidget);
        btn_play->setObjectName(QStringLiteral("btn_play"));

        horizontalLayout_3->addWidget(btn_play);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lineEdit_File = new QLineEdit(centralWidget);
        lineEdit_File->setObjectName(QStringLiteral("lineEdit_File"));
        lineEdit_File->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEdit_File);

        btn_open = new QPushButton(centralWidget);
        btn_open->setObjectName(QStringLiteral("btn_open"));

        horizontalLayout_4->addWidget(btn_open);

        btn_play2 = new QPushButton(centralWidget);
        btn_play2->setObjectName(QStringLiteral("btn_play2"));

        horizontalLayout_4->addWidget(btn_play2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        btn_stop = new QPushButton(centralWidget);
        btn_stop->setObjectName(QStringLiteral("btn_stop"));

        horizontalLayout_6->addWidget(btn_stop);

        btn_record = new QPushButton(centralWidget);
        btn_record->setObjectName(QStringLiteral("btn_record"));

        horizontalLayout_6->addWidget(btn_record);

        btn_stop_record = new QPushButton(centralWidget);
        btn_stop_record->setObjectName(QStringLiteral("btn_stop_record"));

        horizontalLayout_6->addWidget(btn_stop_record);

        btn_snapshot = new QPushButton(centralWidget);
        btn_snapshot->setObjectName(QStringLiteral("btn_snapshot"));

        horizontalLayout_6->addWidget(btn_snapshot);

        btn_open_audio = new QPushButton(centralWidget);
        btn_open_audio->setObjectName(QStringLiteral("btn_open_audio"));

        horizontalLayout_6->addWidget(btn_open_audio);

        btn_close_audio = new QPushButton(centralWidget);
        btn_close_audio->setObjectName(QStringLiteral("btn_close_audio"));

        horizontalLayout_6->addWidget(btn_close_audio);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(horizontalLayout_6, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\234\254\345\234\260\346\226\207\344\273\266\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\347\233\270\345\205\263\346\223\215\344\275\234\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\256\236\346\227\266\346\265\201\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        radioButton_TCP->setText(QApplication::translate("MainWindow", "TCP", Q_NULLPTR));
        radioButton_UDP->setText(QApplication::translate("MainWindow", "UDP", Q_NULLPTR));
        btn_play->setText(QApplication::translate("MainWindow", "\346\222\255\346\224\276", Q_NULLPTR));
        btn_open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        btn_play2->setText(QApplication::translate("MainWindow", "\346\222\255\346\224\276", Q_NULLPTR));
        btn_stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", Q_NULLPTR));
        btn_record->setText(QApplication::translate("MainWindow", "\345\275\225\345\203\217", Q_NULLPTR));
        btn_stop_record->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\345\275\225\345\203\217", Q_NULLPTR));
        btn_snapshot->setText(QApplication::translate("MainWindow", "\346\210\252\345\233\276", Q_NULLPTR));
        btn_open_audio->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\351\237\263\351\242\221", Q_NULLPTR));
        btn_close_audio->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\351\237\263\351\242\221", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
