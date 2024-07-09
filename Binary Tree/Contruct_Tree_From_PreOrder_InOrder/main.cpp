#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <vector>
using namespace std;
// search Function
int search(vector<int>& inorder, int data){
    int index;
    for(int i=0; i<inorder.size(); i++){
        if(inorder[i] == data){
            index = i;
            break;
        }
    }
    return index;
}
// print Tree Level Wise
void printTreeLevelWise(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        //print left child if exist
        if(front->left){
            cout<<"L:-"<<front->left->data<<",";
            pendingNodes.push(front->left);
        }
        // print right child if exist
        if(front->right){
            cout<<"R:-"<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
    
}
// Build Tre Helper Function
BinaryTreeNode<int>* build_Tree_From_InOrder_PreOrder(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd){
    // Edge case
    if(inStart > inEnd) {
        return NULL;
    }
    
    static int preIndex = 0;
    int currentData = preorder[preIndex];
    BinaryTreeNode<int>* TNode = new BinaryTreeNode<int>(currentData);
    preIndex++;
    
    // Base case - if there are no child of current node
    if(inStart == inEnd){
        return TNode;
    }
    
    // find out the index of the current element in the inorder array
    int index = search(inorder, currentData);
    // let's find out the left and right subtree for the current node
    TNode->left = build_Tree_From_InOrder_PreOrder(preorder, inorder, inStart, index-1);
    TNode->right = build_Tree_From_InOrder_PreOrder(preorder, inorder, index+1, inEnd);
    
    return TNode;
    
}
// Build Tree Function
BinaryTreeNode<int>* buildTree(vector<int>& preorder, int preLength, vector<int>& inorder, int inLength){
    BinaryTreeNode<int>* root = build_Tree_From_InOrder_PreOrder(preorder, inorder, 0, inLength-1);
    return root;
}
int main()
{
    vector<int> preOrder { 1, 2, 4, 5, 3, 6, 7 };
    vector<int> inOrder { 4, 2, 5, 1, 6, 3, 7 };
    
    BinaryTreeNode<int>* root = buildTree(preOrder, 7, inOrder, 7);
    
    printTreeLevelWise(root);
    
    delete root;

    return 0;
}
