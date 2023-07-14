#include "workfun.h"

WorkFun::WorkFun(QObject *parent) : QObject(parent)
{

}

void WorkFun::FindNum(){
    Answer_FindNum = 0;
    bool flag = false;
    for(int i = 0; i < 10; ++i){
        if((30 + i) * 6237 / (i * 10 + 3) == 3564 && (30 + i) * 6237 % (i * 10 + 3) == 0){
            Answer_FindNum = i;
            flag = true;
        }
    }
}

void WorkFun::FindRoot(){

}
