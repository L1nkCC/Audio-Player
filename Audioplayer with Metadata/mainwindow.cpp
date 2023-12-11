#include <QFileDialog>
#include <QImage>
#include <cassert>
#include <iostream>
#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <QStyle>

MainWindow::MainWindow(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::MainWindow),
        m_player(new QMediaPlayer(this)),
        m_audioOutput(new QAudioOutput(this)) {
    ui->setupUi(this);
    const auto fileIcon = style()->standardIcon(
            QStyle::StandardPixmap::SP_FileIcon);
    //ui->openButton->setIcon(fileIcon);
    ui->forwardsButton->setIcon(style()->standardIcon(QStyle::StandardPixmap::SP_MediaSkipForward));
    ui->backwardsButton->setIcon(style()->standardIcon(QStyle::StandardPixmap::SP_MediaSkipBackward));
    ui->playButton->setIcon(style()->standardIcon(QStyle::StandardPixmap::SP_MediaPause));
    state = true;
    ui->actionOpen->setIcon(fileIcon);
    m_player->setAudioOutput(m_audioOutput);
    ui->progressBar->setValue(0);


    //setup buttons
    QObject::connect(ui->forwardsButton, SIGNAL(clicked()), this, SLOT(forward5()));
    QObject::connect(ui->backwardsButton, SIGNAL(clicked()), this, SLOT(back5()));
    QObject::connect(ui->playButton, SIGNAL(clicked()), this, SLOT(playPause()));


    //setup PBarUpdated
    QObject::connect(m_player, SIGNAL(positionChanged(qint64)), this, SLOT(updatePBar()));
    QObject::connect(m_player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(statusChange()));

}

void MainWindow::forward5(){
    if(m_player->position()+5000 < m_player->duration())
        m_player->setPosition(m_player->position()+5000);
    else
        m_player->setPosition(m_player->duration());
}

void MainWindow::back5(){
    if(m_player->position()-5000 > 0)
        m_player->setPosition(m_player->position()-5000);
    else
        m_player->setPosition(0);
}

///change Icon
void MainWindow::playPause() {
    if (state) {
        m_player->pause();
        ui->playButton->setIcon(style()->standardIcon(QStyle::StandardPixmap::SP_MediaPlay));
    }else{
        m_player->play();
        ui->playButton->setIcon(style()->standardIcon(QStyle::StandardPixmap::SP_MediaPause));
    }
    state = !state;
}

void MainWindow::updatePBar(){
    ui->progressBar->setValue(m_player->position());
}

void MainWindow::statusChange(){
    switch(m_player->mediaStatus()){
        case QMediaPlayer::MediaStatus::EndOfMedia:
            m_player->setPosition(0);
            playPause();
            break;
        case QMediaPlayer::MediaStatus::LoadedMedia:
            ui->progressBar->setMaximum(m_player->duration());
            ui->progressBar->setMinimum(0);
            ui->progressBar->setValue(0);
            ui->artistLabel->setText(m_player->metaData().stringValue(QMediaMetaData::Key::ContributingArtist));
            ui->songLabel->setText(m_player->metaData().stringValue(QMediaMetaData::Key::Title));
            break;
        default:
            break;
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionQuit_triggered() {
    QApplication::quit();
}

void MainWindow::on_actionOpen_triggered() {
    QString fileName =
            QFileDialog::getOpenFileName(this,
                                         "Open Audio File",
                                         ".",
                                         "Audio Files (*.mp3 *.m4a *.wav)");
    m_player->setSource(QUrl::fromLocalFile(fileName));
    //ui->fileLabel->setText(fileName);
    m_player->play();
}


