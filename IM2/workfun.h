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
    void FindRoot();

signals:

public slots:
};

#endif // WORKFUN_H
