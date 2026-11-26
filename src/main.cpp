#include<iostream>
#include "tree.h"
using namespace std;


int main(){
    tree t;
    t.add(50);
    t.add(40);
    t.add(60);
    t.add(30);
    t.add(45);
    t.add(70);
    t.add(65);
    t.add(25);
    t.add(47);
    t.add(35);
    t.add(49);
    // cout<<t.getParentData(60)<<endl;
    // cout<<t.getParentData(50)<<endl;
    // cout<<t.getParentData(65)<<endl;
    // cout<<t.getParentData(45)<<endl;
    // t.getNodeData(60)? cout<<"Found"<<endl: cout<<"NotFound"<<endl;
    // t.getNodeData(50)? cout<<"Found"<<endl: cout<<"NotFound"<<endl;
    // t.getNodeData(30)? cout<<"Found"<<endl: cout<<"NotFound"<<endl;
    // t.getNodeData(100)? cout<<"Found"<<endl: cout<<"NotFound"<<endl;
    // cout<<t.maxRightData(40)<<endl;
    // cout<<t.maxRightData(50)<<endl;
    // cout<<t.maxRightData(30)<<endl;
    // cout<<t.minLeftData(40)<<endl;
    // cout<<t.minLeftData(50)<<endl;
    // cout<<t.minLeftData(30)<<endl;
    //----------------DELETE ROOT-----------------//
    //t.removeNode(50);
    // cout<<t.getParentData(60)<<"\n";
    //----------------DELETE INTERNAL NODE WITH 2 CHILDREN---------------//
    // t.removeNode(40);
    // cout<<t.getParentData(45)<<"\n";
    // cout<<t.getParentData(30)<<"\n";
    //-------------DELETE INTERNAL NODE WITH 1 CHILD-----------------//
    // t.removeNode(70);//has left child
    // cout<<t.getParentData(65)<<"\n";
    // t.removeNode(47);//has right child
    // cout<<t.getParentData(49)<<"\n";
    //--------------DELETE LEAF NODE---------------------//
    // t.removeNode(25);
    // cout<<t.getParentData(25)<<"\n";
    //-------------------Display LDR USING RECURSION-----------//
    t.displayLDR();
    cout<<"\n";
    cout<<t.maxDepthRec()<<"\n";
    cout<<t.maxDepthBFS()<<"\n";
    return 0;
}