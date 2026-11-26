#ifndef QUEUEARR_H
#define QUEUEARR_H

#include "tree.h"

class queuearr{
    int front,rear;
    int size;
    int count;
    nodeTree** arr;
    public:
    queuearr(int arrsize){
        front=-1;
        rear=-1;
        count=0;
        size=arrsize;
        arr=new nodeTree*[size];
    }
    void enqueue(nodeTree* data);
    nodeTree* dequeue();
    bool isfull();
    bool isempty();
    int getCount();
    ~queuearr(){
        delete[] arr;
    }
};

#endif