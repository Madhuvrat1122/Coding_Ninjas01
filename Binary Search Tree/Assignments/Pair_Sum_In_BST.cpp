// Problem statement
// Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).

// Note:
// 1. Assume BST contains all unique elements.
// 2. In a pair, print the smaller element first.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// Time Limit: 1 second   
// Sample Input 1:
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// 12
// Sample Output 1:
// 2 10
// 5 7

#include<unordered_map>
void printNodesSumToSHelper(BinaryTreeNode<int>* root, int s, unordered_map<int, bool> &mp){
	if(root == NULL){
		return;
	}
	printNodesSumToSHelper(root->left, s, mp);
	if(mp[s-root->data]){
		cout<<s-root->data<<" "<<root->data<<endl;
	}
	mp[root->data] = true;
	printNodesSumToSHelper(root->right, s, mp);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
	unordered_map<int, bool> mp;
	printNodesSumToSHelper(root, s,mp);
}
