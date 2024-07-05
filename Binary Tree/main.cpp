#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;
// print Tree Function
void printTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    // print root data then left and right data if exist
    cout<<root->data<<":";
    if(root->left != NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
// take input Function
BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Data:- "<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* left = takeInput();
    BinaryTreeNode<int>* right = takeInput();
    root->left = left;
    root->right = right;
    return root;
}
int main()
{
    // BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* left = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* right = new BinaryTreeNode<int>(3);
   
    // root->left = left;
    // root->right = right;
    
    BinaryTreeNode<int>* root = takeInput();
    
    printTree(root);
    
    delete root;

    return 0;
}
