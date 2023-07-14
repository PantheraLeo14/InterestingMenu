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

signals:

public slots:
};

#endif // WORKFUN_H
