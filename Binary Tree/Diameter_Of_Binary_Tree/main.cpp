#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;
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
// function to find the heigth and diameter of binary tree
pair<int, int> findHeightAndDaimeter(BinaryTreeNode<int>* root){
    pair<int, int> p;
    if(root == NULL){
        p.first = 0;
        p.second = 0;
        return p;
    }
    
    pair<int, int> leftAns = findHeightAndDaimeter(root->left);
    pair<int, int> rightAns = findHeightAndDaimeter(root->right);
    
    int leftHeight = leftAns.first;
    int leftDaimeter = leftAns.second;
    int rightHeight = rightAns.first;
    int rightDaimeter = rightAns.second;
    
    int height = 1 + max(leftHeight, rightHeight);
    int daimeter = max(leftHeight+rightHeight, max(leftDaimeter, rightDaimeter));
    
    p.first = height;
    p.second = daimeter;
    return p;
}
int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();
    
    pair<int, int> p = findHeightAndDaimeter(root);
    
    cout<<"Height Of Binary Tree:- "<<p.first<<endl;
    cout<<"Daimeter Of Binary Tree:- "<<p.second<<endl;
    
    delete root;

    return 0;
}
