/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionOpen;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *songLabel;
    QLabel *artistLabel;
    QLabel *fileLabel;
    QVBoxLayout *verticalLayout_2;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout;
    QPushButton *backwardsButton;
    QPushButton *playButton;
    QPushButton *forwardsButton;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(424, 203);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        songLabel = new QLabel(centralwidget);
        songLabel->setObjectName("songLabel");

        verticalLayout->addWidget(songLabel);

        artistLabel = new QLabel(centralwidget);
        artistLabel->setObjectName("artistLabel");

        verticalLayout->addWidget(artistLabel);

        fileLabel = new QLabel(centralwidget);
        fileLabel->setObjectName("fileLabel");
        fileLabel->setMinimumSize(QSize(400, 100));

        verticalLayout->addWidget(fileLabel);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        verticalLayout_2->addWidget(progressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        backwardsButton = new QPushButton(centralwidget);
        backwardsButton->setObjectName("backwardsButton");

        horizontalLayout->addWidget(backwardsButton);

        playButton = new QPushButton(centralwidget);
        playButton->setObjectName("playButton");

        horizontalLayout->addWidget(playButton);

        forwardsButton = new QPushButton(centralwidget);
        forwardsButton->setObjectName("forwardsButton");

        horizontalLayout->addWidget(forwardsButton);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 424, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Player", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open...", nullptr));
        songLabel->setText(QCoreApplication::translate("MainWindow", "Song", nullptr));
        artistLabel->setText(QCoreApplication::translate("MainWindow", "Artist", nullptr));
        fileLabel->setText(QString());
        backwardsButton->setText(QString());
        playButton->setText(QString());
        forwardsButton->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
