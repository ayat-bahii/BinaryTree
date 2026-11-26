#ifndef TREE_H
#define TREE_H


struct nodeTree{
    int data;
    nodeTree * left;
    nodeTree * right;
    nodeTree(int data){
        this->data=data;
        left=right=NULL;
    }
};

class tree{
    nodeTree* root;
    nodeTree* getNodeByData(int data);
    nodeTree* getParent(int data);
    nodeTree* maxRight(int data);
    nodeTree* minLeft(int data);
    public:
    tree();
    void add(int data);
    void removeNode(int data);
    int getParentData(int data);
    bool getNodeData(int data);
    int maxRightData(int data);
    int minLeftData(int data);
    void displayLDR(nodeTree* root);
    void displayLDR();
    int maxDepthRec(nodeTree* root);
    int maxi(int ldepth,int rdepth);
    int maxDepthRec();
    int maxDepthBFS(nodeTree* root);
    int maxDepthBFS();
    void destroyTree(nodeTree* root);
    ~tree(){
        destroyTree(root);
        root=NULL;
    }
};

#endif