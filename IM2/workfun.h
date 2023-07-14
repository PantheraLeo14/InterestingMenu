#ifndef WORKFUN_H
#define WORKFUN_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QMessageBox>

class WorkFun : public QObject
{
    Q_OBJECT
public:
    explicit WorkFun(QObject *parent = 0);

    void FindNum();
    int Answer_FindNum;

    void FindRoot(int a, int b, int c);
    double Answer_FindRoot1;
    double Answer_FindRoot2;
    int flag_FindRoot;

    void Detective();
    int Answer_Detective[100][2];
    int Index_Detective;

    void Bear();
    int Answer_Bear;

    void MultiplicationTable();
    QString Answer_MultiTable;
    bool Status_MultiTable;//防止答案多添加多次打印

signals:

public slots:
};

#endif // WORKFUN_H
