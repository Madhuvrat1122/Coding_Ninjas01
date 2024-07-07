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
// count nodes
int countNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
// Find a node
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if(root == NULL){
        return false;
    }   
    else if(root->data == x){
        return true;
    }

    bool ans1 = isNodePresent(root->left, x);
    bool ans2 = isNodePresent(root->right, x);
    if(ans1 || ans2){
        return true;
    }

    return false;
}
// find the height of tree
int height(BinaryTreeNode<int>* root) {
    if(root == NULL){
		return 0;
	}
	int ans = 1, leftHeight = 0, rightHeight = 0;
	if(root->left){
		leftHeight = height(root->left);
	}
	if(root->right){
		rightHeight = height(root->right);
	}

	ans += leftHeight > rightHeight ? leftHeight : rightHeight;
	return ans;
}
// mirror binary tree
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL){
		return;
	}
	// both right and left child exist
	if(root->left && root->right){
		BinaryTreeNode<int>* templeft = root->left;
		root->left = root->right;
		root->right = templeft;

		mirrorBinaryTree(root->left);
		mirrorBinaryTree(root->right);
	}
	// left child exist but not right
	else if(root->left and !root->right){
		root->right = root->left;
		root->left = NULL;
		mirrorBinaryTree(root->right);
	}
	// right child exist but not left
	else if(!root->left and root->right){
		root->left = root->right;
		root->right = NULL;
		mirrorBinaryTree(root->left);
	}
}
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
int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();
    
    cout<<countNodes(root)<<endl; // count number of node
    
    cout<<isNodePresent(root, 10)<<endl; // check node is present or not
    
    cout<<height(root)<<endl; // find the height of tree
    
    mirrorBinaryTree(root); // mirror binary tree
    
    delete root;

    return 0;
}
