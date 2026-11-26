#include<iostream>
#include<cmath>
#include "tree.h"
#include "queuearrr.h"
using namespace std;

tree::tree(){
    root=NULL;
}

void tree::add(int data){
    nodeTree* newNode=new nodeTree(data);
    if(root==NULL){
        root=newNode;
    }
    else{
        nodeTree* current=root;
        nodeTree* parent=NULL;
        while(current!=NULL){
            parent=current;
            if(data > current->data){
                current=current->right;
            }
            else{
                current=current->left;
            }
        }
        if(data > parent->data){
            parent->right=newNode;
        }
        else{
            parent->left=newNode;
        }
    }
}

nodeTree* tree::getNodeByData(int data){
    nodeTree* current=root;
    while(current!=NULL){
        if(current->data==data){
            return current;
        }
        else if(data > current->data){
            current=current->right;
        }
        else{
            current=current->left;
        }
    }
    return NULL;
}

nodeTree* tree::getParent(int data){
    nodeTree* current=getNodeByData(data);
    if(current==NULL || current==root){
        return NULL;
    }
    nodeTree* parent=root;
    while(parent!=NULL){
        if(parent->left==current||parent->right==current){
            return parent;
        }
        else if(data > parent->data){
            parent=parent->right;
        }
        else{
            parent=parent->left;
        }
    }
    return NULL;
}

bool tree::getNodeData(int data){
    nodeTree* current=getNodeByData(data);
    if(current==NULL){
        return false;
    }
    return true;
}

int tree::getParentData(int data){
    nodeTree* current=getParent(data);
    if(current==NULL){
        return -1;
    }
    return current->data;
}

nodeTree* tree::maxRight(int data){
    nodeTree* current=getNodeByData(data);
    if(current==NULL){
        return NULL;
    }
    while(current->right!=NULL){
        current=current->right;
    }
    return current;
}

nodeTree* tree::minLeft(int data){
    nodeTree* current=getNodeByData(data);
    if(current==NULL){
        return NULL;
    }
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}

int tree::maxRightData(int data){
    nodeTree* current=maxRight(data);
    if(current==NULL){
        return -1;
    }
    return current->data;
}

int tree::minLeftData(int data){
    nodeTree* current=minLeft(data);
    if(current==NULL){
        return -1;
    }
    return current->data;
}

void tree::removeNode(int data){
    nodeTree* current=getNodeByData(data);
    if(current==NULL){
        return ;
    }
    if(current==root){
        if(current->left==NULL && current->right==NULL){
            root=NULL;
        }
        else if(current->left == NULL){
            root=current->right;
        }
        else if(current->right == NULL){
            root=current->left;
        }
        else{
            nodeTree* newRoot=root->left;
            nodeTree* maxRightNode = maxRight(newRoot->data);
            maxRightNode->right=root->right;
            root = newRoot;
        }
    }else{
        nodeTree* parent=getParent(current->data);
        if(current->left==NULL && current->right==NULL){
            if(current->data > parent->data){
                parent->right=NULL;
            }
            else{
                parent->left=NULL;
            }
        }
        else if(current->left==NULL){
            if(current->data > parent->data){
                parent->right=current->right;
            }
            else{
                parent->left=current->right;
            }
        }else if(current->right==NULL){
            if(current->data > parent->data){
                parent->right=current->left;
            }
            else{
                parent->left=current->left;
            }
        }else{
            nodeTree* leftCurrent=current->left;
            nodeTree* maxxRightNode=maxRight(leftCurrent->data);
            if(current->data > parent->data){
                parent->right=leftCurrent;
                maxxRightNode->right=current->right;
            }else{
                parent->left=leftCurrent;
                maxxRightNode->right=current->right;
            }
        }

    }
    delete current;
}


void tree::displayLDR(nodeTree* root){
    if(root==NULL){
        return;
    }
    displayLDR(root->left);
    cout<<root->data<<" ";
    displayLDR(root->right);
}

void tree::displayLDR() {
    displayLDR(root);
}

int tree::maxi(int ldepth,int rdepth){
    if(ldepth > rdepth){
        return ldepth;
    }
    return rdepth;
}

int tree::maxDepthRec(nodeTree* root){
    if(root==NULL){
        return 0;
    }
    int ldepth=maxDepthRec(root->left);
    int rdepth=maxDepthRec(root->right);

    return maxi(ldepth,rdepth)+1;
}

int tree::maxDepthRec(){
    return maxDepthRec(root);
}

int tree::maxDepthBFS(nodeTree* root){
    if(root==NULL){
        return 0;
    }
    queuearr q(100);
    q.enqueue(root);
    int maxH=0;
    while(!q.isempty()){
        int levels=q.getCount();
        for(int i=0;i<levels;i++){
            nodeTree* current=q.dequeue();
            if(current->left!=NULL){
                q.enqueue(current->left);
            }
            if(current->right!=NULL){
                q.enqueue(current->right);
            }
        }
        maxH++;
    }
    return maxH;
}

int tree::maxDepthBFS(){
    return maxDepthBFS(root);
}
