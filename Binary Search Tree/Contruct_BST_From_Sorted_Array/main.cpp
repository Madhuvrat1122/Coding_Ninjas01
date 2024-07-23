#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;
// Contruct BST Through binary Search
BinaryTreeNode<int>* constructTreeBinarySearch(int *input, int low, int high) {
	// base  case
	if(low > high){
	    return NULL;
	}
	// generate node for the current element
	int mid = ( low + high ) / 2;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
	// single element in array
	if(low == high){
	    return root;
	}
	// if more then one element then 
	root->left = constructTreeBinarySearch(input, low, mid-1);
	root->right = constructTreeBinarySearch(input, mid+1, high);
	
	return root;
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
// Contruct Binary Search Tree from sorted array
BinaryTreeNode<int>* constructTree(int *input, int n) {
	return constructTreeBinarySearch(input, 0, n-1);
}
int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = 6;
    
    BinaryTreeNode<int>* root = constructTree(arr, n);
    
    printTreeLevelWise(root);
    
    delete root;

    return 0;
}

// 40 10 50 8 11 49 60 -1 -1 -1 -1 -1 -1 -1 -1 
