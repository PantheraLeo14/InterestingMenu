#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    initWindow();
    ui->setupUi(this);
}






void MainWindow::initMenu(){
    FindNum = new QMenu("&FindNum");
    FindRoot = new QMenu("&FindRoot");
    Detective = new QMenu("&Detective");
    Bear = new QMenu("&Bear");
    MultiplicationTable = new QMenu("&MultiplicationTable");
    Goodbye = new QMenu("&Goodbye");

    FindNum->addAction(action_FindNum);
    FindRoot->addAction(action_FindRoot);
    Detective->addAction(action_Detective);
    Bear->addAction(action_Bear);
    MultiplicationTable->addAction(action_MultiplicationTable);
    Goodbye->addAction(action_Goodbye);

    menuBar()->addMenu(FindNum);
    menuBar()->addMenu(FindRoot);
    menuBar()->addMenu(Detective);
    menuBar()->addMenu(Bear);
    menuBar()->addMenu(MultiplicationTable);
    menuBar()->addMenu(Goodbye);
}

void MainWindow::initAction(){
    action_FindNum = new QAction(this);
    action_FindRoot = new QAction(this);
    action_Detective = new QAction(this);
    action_Bear = new QAction(this);
    action_MultiplicationTable = new QAction(this);
    action_Goodbye = new QAction(this);
    action_Clear = new QAction(this);

    action_Clear->setIcon(QIcon(":/res/clear.png"));

    action_FindNum->setText("FindNum");
    action_FindRoot->setText("FindRoot");
    action_Detective->setText("Detective");
    action_Bear->setText("Bear");
    action_MultiplicationTable->setText("MultiplicationTable");
    action_Goodbye->setText("Goodbye");
    action_Clear->setText("Clear");
}

void MainWindow::initToolBar(){
    toolbar = addToolBar("toolbar");
    toolbar->addAction(action_FindNum);
    toolbar->addAction(action_FindRoot);
    toolbar->addAction(action_Detective);
    toolbar->addAction(action_Bear);
    toolbar->addAction(action_MultiplicationTable);
    toolbar->addAction(action_Goodbye);
    toolbar->addAction(action_Clear);
}

void MainWindow::initConnection(){
    connect(action_FindNum, &QAction::triggered, this, &MainWindow::ActFindNum);
    connect(action_FindRoot, &QAction::triggered, this, &MainWindow::ActFindRoot);
    connect(action_Detective, &QAction::triggered, this, &MainWindow::ActDetective);
    connect(action_Bear, &QAction::triggered, this, &MainWindow::ActBear);
    connect(action_MultiplicationTable, &QAction::triggered, this, &MainWindow::ActMultiplicationTable);
    connect(action_Goodbye, &QAction::triggered, this, &MainWindow::ActGoodbye);
    connect(action_Clear, &QAction::triggered, this, &MainWindow::ActClear);
}

void MainWindow::ActFindNum(){
    setBackground(2);
    line1 = new QLineEdit(this);
    line2 = new QLineEdit(this);
    line1->setPlaceholderText("请输入数字");
    line2->setPlaceholderText("请输入数字");
    line1->move(200,200);
    line2->move(400,200);
}

void MainWindow::ActFindRoot(){

}

void MainWindow::ActDetective(){

}

void MainWindow::ActBear(){

}

void MainWindow::ActMultiplicationTable(){

}

void MainWindow::ActClear(){
    setBackground(1);
}

void MainWindow::ActGoodbye(){
//    qDebug() << "NO Bug\n";
    this->close();
}

void MainWindow::setBackground(int i){
    QPixmap bkgnd;
    if(i == 1) bkgnd.load(":/res/welcome.png");
    else if(i == 2) bkgnd.load(":/res/clear.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

void MainWindow::initWindow(){
    setFixedSize(800,600);
    setBackground(1);
    initAction();
    initMenu();
    initToolBar();
    initConnection();
}

MainWindow::~MainWindow()
{
    delete action_FindRoot;
    delete action_FindNum;
    delete action_Detective;
    delete action_Bear;
    delete action_MultiplicationTable;
    delete action_Goodbye;

    delete FindRoot;
    delete FindNum;
    delete Detective;
    delete Bear;
    delete MultiplicationTable;
    delete Goodbye;

    delete toolbar;

    delete ui;
}
