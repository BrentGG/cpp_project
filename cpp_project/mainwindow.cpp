#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worldview.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    WorldView *worldView = new WorldView();
    setCentralWidget(worldView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

