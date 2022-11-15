#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamecontroller.h"
#include "canvas.h"
#include "characterdrawing.h"

#include <QMainWindow>
#include <QKeyEvent>

#include <chrono>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui;

    GameController* gameController;

    Canvas* canvas;
    CharacterDrawing* canvasDrawing;

    std::chrono::time_point<std::chrono::high_resolution_clock> timeDeltaStart;

private slots:
    void updateView();
};
#endif // MAINWINDOW_H
