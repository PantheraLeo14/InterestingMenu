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

void MainWindow::initLineEdit(){
    if(!Status_Line){
        line1 = new QLineEdit(this);
        line2 = new QLineEdit(this);
        line1->resize(20,20);
        line2->resize(20,20);
        line1->setVisible(true);
        line2->setVisible(true);
        Status_Line = true;
    }
    else return;
}

void MainWindow::closeLineEdit(){//bugs need repairing
    line1->setVisible(false);
    line2->setVisible(false);
    Status_Line = false;
}

void MainWindow::closePushButton(){
//    Button1->setVisible(false);
    if(Button1 != nullptr){
        delete Button1;
        Button1 = nullptr;
    }
    Status_Button = false;
}

void MainWindow::initPushButton(QWidget *widget){
    if(!Status_Button){
        Button1 = new QPushButton(widget);
        Button1->setVisible(true);
        Button1->resize(100,50);
        Button1->move(335, 400);
        Button1->setText("执行程序");
        Button1->setVisible(true);
        Status_Button = true;
    }
    else return;
}

void MainWindow::initLabel(){
    if(!Status_Label){
        label1 = new QLabel(this);
        label2 = new QLabel(this);
        label3 = new QLabel(this);
        label4 = new QLabel(this);
        label_answer = new QLabel(this);
        label1->setText("3");
        label2->setText("*6237=3");
        label3->setText("*3564");
        label1->setVisible(true);
        label2->setVisible(true);
        label3->setVisible(true);
        Status_Label = true;
    }
    else return;
}

void MainWindow::closeLabel(){
//    label1->setVisible(false);
//    label2->setVisible(false);
//    label3->setVisible(false);
//    label4->setVisible(false);
    if(label1 != nullptr){
        delete label1;
        label1 = nullptr;
    }
    if(label2 != nullptr){
        delete label2;
        label2 = nullptr;
    }
    if(label3 != nullptr){
        delete label3;
        label3 = nullptr;
    }
    if(label4 != nullptr){
        delete label4;
        label4 = nullptr;
    }
    Status_Label = false;
}

void MainWindow::initWidget(){
    if(Status_Widget) return;
    widget = new QWidget(this);
    widget->setLayout(layout1);
    this->setCentralWidget(widget);
    Status_Widget = true;
}

void MainWindow::closeWidget(){
    if(widget != nullptr) delete widget;
    Status_Widget = false;
}

void MainWindow::ActFindNum(){
    initLineEdit();
    initLabel();
    layout1 = new QHBoxLayout(this);
    layout1->addWidget(label1);
    layout1->addWidget(line1);
    layout1->addWidget(label2);
    layout1->addWidget(line2);
    layout1->addWidget(label3);
    initWidget();
    label4->setText("ANSWER:");
    label4->move(335, 375);
    label4->setVisible(true);
    initPushButton(widget);
    connect(Button1, &QPushButton::clicked, this, &MainWindow::WorkFindNum);
}

void MainWindow::WorkFindNum(){
    work.FindNum();
    QString answer = "ANSWER:" + QString::number(work.Answer_FindNum);
    label4->setText(answer);
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
    if(Status_Line)closeLineEdit();
    if(Status_Label)closeLabel();
    if(Status_Button)closePushButton();
    if(Status_Widget)closeWidget();
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
    Status_Button = false;
    Status_Label = false;
    Status_Line = false;
    Status_Widget = false;
    Status_Clear = false;
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
