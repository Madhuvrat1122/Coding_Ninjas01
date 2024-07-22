#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;
// Check BST - Apporach 1
bool isBST1(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(min > root->data || max < root->data){
        return false;
    }
    
    bool checkLeft = isBST1(root->left, min, root->data-1); // check for left subtree with new limits
    bool  checkright = isBST1(root->right, root->data, max); // check for right subtree with new limits
    
    return checkLeft && checkright;
}
// check BST - Apporach 2
class BSTType {
    public:
        bool isBST;
        int min;
        int max;
};
BSTType isBST2(BinaryTreeNode<int>* root){
    if(root == NULL){
        BSTType ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.isBST = true;
        return ans;
    }
    BSTType leftAns = isBST2(root->left);
    BSTType rightAns = isBST2(root->right);
    int minimum = min(root->data, min(leftAns.min, rightAns.min));
    int maximum = max(root->data, max(leftAns.max, rightAns.max));
    bool isBSTFINAL = ( leftAns.max < root->data ) && ( rightAns.min >= root->data ) && leftAns.isBST && rightAns.isBST;
    
    BSTType finalAns;
    finalAns.min = minimum;
    finalAns.max = maximum;
    finalAns.isBST = isBSTFINAL;
    return finalAns;
    
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
    
    cout<<isBST1(root)<<endl; // top to down apporach
    
    cout<<isBST2(root).isBST<<endl; // Apporach - 2
    
    delete root;

    return 0;
}

// 40 10 50 8 11 49 60 -1 -1 -1 -1 -1 -1 -1 -1 
