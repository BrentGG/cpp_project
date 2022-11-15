#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameController = new GameController();

    canvas = new Canvas();
    setCentralWidget(canvas);

    setFocusPolicy(Qt::StrongFocus);

    // Create canvas drawings
    canvasDrawing = new CharacterDrawing(gameController->getPlayer());
    canvas->addDrawing(canvasDrawing);

    // Set timer to update view
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateView);
    timer->start(1000/60); // target fps = 60
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    gameController->keyPressed(event->key());
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    gameController->keyReleased(event->key());
}

void MainWindow::updateView()
{
    gameController->tick();
    canvas->updateCanvas();
    update();
}

