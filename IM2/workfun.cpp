#include "workfun.h"

WorkFun::WorkFun(QObject *parent) : QObject(parent)
{

}

void WorkFun::FindNum(){
    Answer_FindNum = 0;
    for(int i = 0; i < 10; ++i){
        if((30 + i) * 6237 / (i * 10 + 3) == 3564 && (30 + i) * 6237 % (i * 10 + 3) == 0){
            Answer_FindNum = i;
        }
    }
}

void WorkFun::FindRoot(int a, int b, int c){
    int tmp1;
    double tmp2;
    flag_FindRoot = 0;
    if(b * b - 4 * a * c < 0){
        //没有root
        flag_FindRoot = 1;
        return;
    }
    else if(b * b - 4 * a * c == 0) flag_FindRoot = 2;
    for(tmp1 = 0; tmp1 * tmp1 <= b * b - 4 * a * c; ++tmp1);
    --tmp1;
    for(tmp2 = tmp1; tmp2 * tmp2 <= b * b - 4 * a * c; tmp2 +=0.01);
    tmp2-=0.01;
    Answer_FindRoot1 = (tmp2 - b) / (2 * a);
    Answer_FindRoot2 = Answer_FindRoot1;
    if(flag_FindRoot == 2) Answer_FindRoot2 = (-tmp2 - b) / (2 * a);
    //得到根
}

void WorkFun::Detective(){

}
