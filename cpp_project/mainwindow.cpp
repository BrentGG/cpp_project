#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tetrisscreen.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TetrisScreen *tetrisScreen = new TetrisScreen();
    setCentralWidget(tetrisScreen);
}

MainWindow::~MainWindow()
{
    delete ui;
}

