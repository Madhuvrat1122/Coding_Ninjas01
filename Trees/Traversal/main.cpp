#include "TreeNode.h"
#include <iostream>
#include <queue>
using namespace std;
// Take Input Level Wise
TreeNode<int>* TakeInputLevelWise(){
    int rootData;
    cout<<"Enter Root Data:- "<<endl;
    cin>>rootData;
    
    // Root Node
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    // Queue
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode<int>* front = q.front();
        q.pop();
        
        int childCount;
        cout<<"Enter No. Of Children For "<<front->data<<":- "<<endl;
        cin>>childCount;
        
        for(int i=0; i<childCount; i++){
            int childData;
            cout<<"Enter "<<i<<"th child for "<<front->data<<":- "<<endl;
            cin>>childData;
            
            TreeNode<int>* childNode = new TreeNode<int>(childData);
            // pushing the child node into queue
            q.push(childNode);
            // connecting the child with the parent
            front->children.push_back(childNode);
        }
    }
    
    return root;
}
//print pre order
void preOrder(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0; i<root->children.size(); i++){
        preOrder(root->children[i]);
    }
}
// print post order
void postOrder(TreeNode<int>* root){
    for(int i=0; i<root->children.size(); i++){
        postOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}
int main()
{
    // Take Input
    TreeNode<int>* root = TakeInputLevelWise();
    
    cout<<"Pre Order:- "<<endl;
    // print preOrder
    preOrder(root);
    
    cout<<endl;
    cout<<"Post Order:- "<<endl;
    // print postOrder
    postOrder(root);

    // delete Tree => this will call the destructor of TreeNode class
    delete root;
    
    return 0;
}


// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
