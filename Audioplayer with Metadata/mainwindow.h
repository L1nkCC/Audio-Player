#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

    ~MainWindow() override;

private slots:

    void back5();

    void forward5();

    void playPause();

    void updatePBar();

    void statusChange();

    void on_actionQuit_triggered();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow* ui;
    QMediaPlayer* m_player;
    QAudioOutput* m_audioOutput;
    bool state;
};

#endif //MAINWINDOW_H
