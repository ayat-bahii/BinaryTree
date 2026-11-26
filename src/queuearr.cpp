#include<iostream>
#include "queuearrr.h"
using namespace std;

bool queuearr::isfull(){
    if(((front==0)&&(rear==size-1))||(rear+1==front)){
        return true;
    }
    return false;
}
bool queuearr::isempty(){
    if(((front==-1)&&(rear==-1))){
        return true;
    }
    return false;

}

void queuearr::enqueue(nodeTree* data){
    if(isfull()){
       cout<<"Queue is full\n";
    }
    else{
        if(front==-1){
            front++;
        }
        if(rear==size-1){
        rear=-1;
        }
        rear++;
        arr[rear]=data;
        count++;
    }
}

nodeTree* queuearr::dequeue(){
    if(isempty()){
        cout<<"Queue is empty\n";
        return NULL;
    }
    else{
        count--;
        nodeTree* tmp=arr[front];
        arr[front]=0;
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            if(front==size-1){
                front=-1;
            }
            front++;
        }
        return tmp;
    }
}

int queuearr::getCount(){
    return count;
}