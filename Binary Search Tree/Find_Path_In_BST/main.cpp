#include <iostream>
#include "BinaryTreeNode.h"
#include <vector>
#include <queue>
using namespace std;
// Get Path In Binary Tree
vector<int>* getPathInBst(BinaryTreeNode<int>* root, int data){
    if(root == NULL){
        return NULL;
    }
    // if root data is the current data then return root data
    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    
    // if root is not the current data then look in left subtree
    vector<int>* leftVector = getPathInBst(root->left, data);
    // if we found the data in left side
    if(leftVector != NULL){
        leftVector->push_back(root->data);
        return leftVector;
    }
    // if we don't found the data in left side then let's check in right side
    vector<int>* rightVector = getPathInBst(root->right, data);
    // if we found the data in right subtree
    if(rightVector != NULL){
        rightVector->push_back(root->data);
        return rightVector;
    }
    // we didn't found the data neither in left subtree nor right subtree
    else {
        return NULL;
    }
}
// Take Input Level Wise
BinaryTreeNode<int>* takeInputLevelWise(){
    // Taking Root Input
    int rootData;
    cout<<"Enter Root Data:- "<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    
    // queue to store the nodes for which we need to take left and right input
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        
        //take left input
        int leftData;
        cout<<"Enter left child of "<<front->data<<endl;
        cin>>leftData;
        // - 1 means user don't want any child
        if(leftData != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftData);
            front->left = leftNode;
            pendingNodes.push(leftNode);
        }
         
        // take right input
        int rightData;
        cout<<"Enter right child of "<<front->data<<endl;
        cin>>rightData;
        // - 1 means user don't want any child
        if(rightData != -1){
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightData);
            front->right = rightNode;
            pendingNodes.push(rightNode);
        }
    }
    
    return root;
}
int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();
    // binary Tree => 1 3 2 4 5 6 7 -1 -1 -1 -1 9 10 -1 -1 -1 -1 -1 -1
    // data for search => 10
    vector<int>* output = getPathInBst(root, 10);
    
    // print vector
    cout<<"Path is:- "<<endl;
    for(int i=0; i<output->size(); i++){
        cout<<output->at(i)<<"->";
    }
    
    delete output;
    delete root;

    return 0;
}

// 40 10 50 8 11 49 60 -1 -1 -1 -1 -1 -1 -1 -1 
