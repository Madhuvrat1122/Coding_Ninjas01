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
// In-Order Traversal
void InOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<"->";
    InOrder(root->right);
}
// Pre-Order Traversal
void PreOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<"->";
    PreOrder(root->left);
    PreOrder(root->right);
}
// Post-Order Traversal
void PostOrder(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<"->";
}
// Level Order Traversal
void LevelOrder(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        // print root
        cout<<front->data<<"->";
        // print left child
        if(front->left){
            pendingNodes.push(front->left);
        }
        // print right child
        if(front->right){
            pendingNodes.push(front->right);
        }
    }
}
int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();
    
    InOrder(root); // In-Order Traversal
    
    cout<<endl;
    
    PreOrder(root); // Pre-Order Traversal
    
    cout<<endl;
    
    PostOrder(root); // Post Order Traversal
    
    cout<<endl;
    
    LevelOrder(root); // Level Order Traversal
    
    delete root;

    return 0;
}
