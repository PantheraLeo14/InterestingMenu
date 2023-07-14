#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QDebug>
#include <QPixmap>
#include <QIcon>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include "workfun.h"
#include <QLabel>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initMenu();

    void initWindow();

    void setBackground(int i);

    void initAction();

    void initToolBar();

    void initConnection();

    void initLineEdit();
    void closeLineEdit();

    void initPushButton(QWidget *widget);
    void closePushButton();

    void initLabel();
    void closeLabel();

    void initWidget();
    void closeWidget();

    void closeLayout();

    void ActFindNum();
    void WorkFindNum();

    void ActFindRoot();
    void WorkFindRoot();

    void ActDetective();
    void WorkDetective();

    void ActBear();
    void WorkBear();

    void ActMultiplicationTable();
    void WorkMultiplicationTable();

    void ActGoodbye();
    void ActClear();

//试图写一个转化函数，结果发现是const型，不强制更改cv值就放弃了，去使用原生的toint函数.
//    int ConverStringToInt(QString a);

    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;

    QAction *action_FindNum;
    QAction *action_FindRoot;
    QAction *action_Detective;
    QAction *action_Bear;
    QAction *action_MultiplicationTable;
    QAction *action_Goodbye;
    QAction *action_Clear;

    QMenu *FindNum;
    QMenu *FindRoot;
    QMenu *Detective;
    QMenu *Bear;
    QMenu *MultiplicationTable;
    QMenu *Goodbye;
    QMenu *Clear;

    QToolBar *toolbar;

    QLineEdit *line1;
    QLineEdit *line2;
    QLineEdit *line3;

    QHBoxLayout *layout1;

    QPushButton *Button1;

    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;

    QWidget *widget;

    QPixmap *bkgnd;
    QPalette *palette;

    bool Status_Line;  //避免各个init函数创建时候崩溃以及clear时候崩溃
    bool Status_Button;
    bool Status_Label;
    bool Status_Widget;
    bool Status_Layout;

    WorkFun work;

};

#endif // MAINWINDOW_H
