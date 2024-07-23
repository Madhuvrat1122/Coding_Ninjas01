#include <iostream>
#include "BinaryTreeNode.h"
#include "Node.h"
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;
// print linked list
void printLinkedList(Node<int>* head){
    Node<int>* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
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
// Contruct Linked List Helper Function
pair<Node<int>*, Node<int>*> constructLinkedListHelper(BinaryTreeNode<int>* root) {
	// edge case -1 
	if(root == NULL){
		pair<Node<int>*, Node<int>*> ans;
		ans.first = NULL;
		ans.second = NULL;
		return ans;
	}

	Node<int>* head = new Node<int>(root->data);
	pair<Node<int>*,Node<int>*> leftLL = constructLinkedListHelper(root->left);
	pair<Node<int>*,Node<int>*> rightLL = constructLinkedListHelper(root->right);

	pair<Node<int>*, Node<int>*> answer;

	// edge case - 2
	if(leftLL.first == NULL){
		answer.first = head;
	}
	else {
		if(leftLL.second == NULL){
			leftLL.first->next = head;
		}
		else {
			leftLL.second->next = head;
		}
		answer.first = leftLL.first;
	}

	// edge case - 3
	if(rightLL.first == NULL){
		answer.second = head;
	}
	else {
		head->next = rightLL.first;
		if(rightLL.second){
			answer.second =  rightLL.second;
		}
		else {
			answer.second = rightLL.first;
		}
	}

	return answer;
	
}
// Contruct Linked List
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	return constructLinkedListHelper(root).first;
}
int main()
{
    
    
    BinaryTreeNode<int>* root = takeInputLevelWise();
    Node<int>* head = constructLinkedList(root);
    printLinkedList(head);
    
    delete root;

    return 0;
}

// 40 10 50 8 11 49 60 -1 -1 -1 -1 -1 -1 -1 -1 
