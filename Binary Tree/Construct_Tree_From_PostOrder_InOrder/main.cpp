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
BinaryTreeNode<int>* build_Tree_From_InOrder_PostOrder(vector<int>& postorder, vector<int>& inorder, int inStart, int inEnd, int *iIndex){
    // Edge case
    if(inStart > inEnd) {
        return NULL;
    }
    
    int currentData = postorder[*iIndex];
    BinaryTreeNode<int>* TNode = new BinaryTreeNode<int>(currentData);
    (*iIndex)--;
    
    // Base case - if there are no child of current node
    if(inStart == inEnd){
        return TNode;
    }
    
    // find out the index of the current element in the inorder array
    int index = search(inorder, currentData);
    // let's find out the left and right subtree for the current node
    // first making for right because post order is like this -> left->right->root
    TNode->right = build_Tree_From_InOrder_PostOrder(postorder, inorder, index+1, inEnd, iIndex);
    TNode->left = build_Tree_From_InOrder_PostOrder(postorder, inorder, inStart, index-1, iIndex);
    
    return TNode;
    
}
// Build Tree Function
BinaryTreeNode<int>* buildTree(vector<int>& postOrder, int postLength, vector<int>& inorder, int inLength){
    int iIndex = inLength-1;
    BinaryTreeNode<int>* root = build_Tree_From_InOrder_PostOrder(postOrder, inorder, 0, inLength-1, &iIndex);
    return root;
}
int main()
{
    vector<int> postOrder { 4, 5, 2, 6, 7, 3, 1  };
    vector<int> inOrder { 4, 2, 5, 1, 6, 3, 7  };
    
    BinaryTreeNode<int>* root = buildTree(postOrder, 7, inOrder, 7);
    
    printTreeLevelWise(root);
    
    delete root;

    return 0;
}
