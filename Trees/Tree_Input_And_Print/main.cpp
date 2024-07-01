#include <iostream>
#include "TreeNode.h"
using namespace std;
// print Tree
void printTree(TreeNode<int>* root){
    // Edge Case Not base Case
    if(root == NULL){
        return;
    }
    
    cout<<root->data<<":";
    for(int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
}
// Take Input
TreeNode<int>* TakeInput(){
    int data, n;
    cout<<"Enter Data:- ";
    cin>>data;
    
    // Creating node
    TreeNode<int>* root = new TreeNode<int>(data);
    
    // Taking children Input
    cout<<"Enter Number of Child For "<<data;
    cin>>n;
    
    // taking input for n Child
    for(int i=0; i<n; i++){
        TreeNode<int> *child = TakeInput();
        root->children.push_back(child);
    }
    
    return root;
}

int main()
{
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);
    
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    
    // Take Input
    TreeNode<int>* root = TakeInput();
    
    // print Tree
    printTree(root);
    
    return 0;
}

/*
I/P:-
Enter Data:- 1
Enter Number of Child For 1 :- 1
Enter Data:- 2
Enter Number of Child For 2 :- 1
Enter Data:- 3
Enter Number of Child For 3 :- 0
O/P:-
1:2,
2:3,
3:
*/
