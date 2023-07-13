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

    void ActFindNum();
    void ActFindRoot();
    void ActDetective();
    void ActBear();
    void ActMultiplicationTable();
    void ActGoodbye();
    void ActClear();

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
    QHBoxLayout *layout1;

};

#endif // MAINWINDOW_H
