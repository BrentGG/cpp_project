#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playerdrawing.h"
#include "zombiedrawing.h"

#include <QTimer>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameController = new GameController();

    canvas = new Canvas();
    setCentralWidget(canvas);

    setFocusPolicy(Qt::StrongFocus);

    // Create canvas drawings
    canvas->addDrawing(new PlayerDrawing(gameController->getPlayer()));
    for (int i = 0; i < gameController->getEnemies().size(); ++i) {
        if (gameController->getEnemyTypes()[i] == ZOMBIE)
            canvas->addDrawing(new ZombieDrawing((Zombie*) gameController->getEnemies()[i]));
    }

    // Set timer to update view
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateView);
    timer->start(1000/60); // target fps = 60
    timeDeltaStart = std::chrono::high_resolution_clock::now();
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
    std::chrono::time_point<std::chrono::high_resolution_clock> timeDeltaEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> timeDelta = timeDeltaEnd - timeDeltaStart;
    timeDeltaStart = timeDeltaEnd;
    gameController->tick(timeDelta.count() * 1000);
    canvas->updateCanvas();
    update();
}

