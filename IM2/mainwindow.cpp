#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    initWindow();
    ui->setupUi(this);
}

//int MainWindow::ConverStringToInt(QString a){
//    int answer = 0;
//    for(size_t i = 0; i < a.size(); ++i){
//        answer = answer * 10 + a.at(i).unicode() - '0';
//    }
//    return answer;
//}

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
    if(Status_Line == true) ActClear();
    line1 = new QLineEdit(this);
    line2 = new QLineEdit(this);
    line3 = new QLineEdit(this);
    line1->resize(20,20);
    line2->resize(20,20);
    line3->resize(20,20);

    Status_Line = true;
}

void MainWindow::closeLineEdit(){//bugs need repairing
    if(line1 != nullptr) delete line1;
    if(line2 != nullptr) delete line2;
    if(line3 != nullptr) delete line3;
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
    if(Status_Button == true) ActClear();
    Button1 = new QPushButton(widget);
    Button1->setVisible(true);
    Button1->resize(100,50);
    Button1->move(335, 400);
    Button1->setText("执行程序");
    Button1->setVisible(true);
    Status_Button = true;
}

void MainWindow::initLabel(){
    if(Status_Label == true) ActClear();
    label1 = new QLabel(this);
    label2 = new QLabel(this);
    label3 = new QLabel(this);
    label4 = new QLabel(this);

    Status_Label = true;
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

void MainWindow::closeLayout(){
    if(layout1 != nullptr) delete layout1;
    Status_Layout = false;
}

void MainWindow::ActFindNum(){
    ActClear();
    initLineEdit();
    line1->setVisible(true);
    line2->setVisible(true);
    line3->setVisible(false);
    initLabel();
    label1->setText("3");
    label2->setText("*6237=3");
    label3->setText("*3564");
    label1->setVisible(true);
    label2->setVisible(true);
    label3->setVisible(true);
    Status_Layout = true;
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
    ActClear();
    initLineEdit();
    line1->setVisible(true);
    line2->setVisible(true);
    line3->setVisible(true);
    initLabel();
    label1->setText("X^2+");
    label2->setText("X+");
    label3->setText("=0");
    label1->setVisible(true);
    label2->setVisible(true);
    label3->setVisible(true);
    label4->setText("ANSWER:");
    label4->move(335, 375);
    label4->resize(300,50);
    label4->setVisible(true);
    layout1 = new QHBoxLayout(this);
    layout1->addWidget(line1);
    layout1->addWidget(label1);
    layout1->addWidget(line2);
    layout1->addWidget(label2);
    layout1->addWidget(line3);
    layout1->addWidget(label3);
    initWidget();
    initPushButton(widget);
    connect(Button1, &QPushButton::clicked, this, &MainWindow::WorkFindRoot);
}

void MainWindow::WorkFindRoot(){
    int a, b, c;
    bool ok;                        //DEBUG:需要一个ok的bool值才可以转换
    a = line1->text().toInt(&ok);
    b = line2->text().toInt(&ok);
    c = line3->text().toInt(&ok);
    work.FindRoot(a, b, c);
    QString answer;
    if(work.flag_FindRoot == 1) answer = "NO ROOT";
    else{
         answer = "ROOT: " + QString::number(work.Answer_FindRoot1);
         answer = answer + " ";
         answer = answer + QString::number(work.Answer_FindRoot2);
    }
    label4->setText(answer);
}

void MainWindow::ActDetective(){

}

void MainWindow::ActBear(){

}
s
void MainWindow::ActMultiplicationTable(){

}

void MainWindow::ActClear(){//DEBUG::Clear时候一定要确定已经创建才删除，避免报错
    setBackground(1);
    if(Status_Line)closeLineEdit();
    if(Status_Label)closeLabel();
    if(Status_Button)closePushButton();
    if(Status_Layout)closeLayout();//DEBUG::先删除layout再删除widget，顺序错误会报错
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
    Status_Layout = false;
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

    ActClear();

    delete ui;
}
