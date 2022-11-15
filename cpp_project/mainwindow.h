#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamecontroller.h"
#include "canvas.h"
#include "characterdrawing.h"

#include <QMainWindow>
#include <QKeyEvent>

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

private slots:
    void updateView();
};
#endif // MAINWINDOW_H
