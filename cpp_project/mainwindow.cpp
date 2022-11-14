#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameController = new GameController();

    Canvas *canvas = new Canvas();
    setCentralWidget(canvas);
}

MainWindow::~MainWindow()
{
    delete ui;
}

