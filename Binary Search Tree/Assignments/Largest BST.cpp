// Hard - Problem statement
// Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.

// Note :
// The binary tree will be consisting of only unique elements.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 ≤ Number of nodes ≤ 10^5
// 1 ≤ Data of a node ≤ 10^6
// Time Limit: 1 second
// Sample Input 1:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1


// Sample Output 1:
// 2

/**********************************************************
***********************************************************/
#include <limits.h>
class Info{
	public: 
	bool isBst;
	int minVal;
	int maxVal;
	int height;
};
Info largestBSTSubtreeHelper(BinaryTreeNode<int> *root, int &maxHeight){
	if(root == NULL){
		Info result;
		result.height = 0;
		result.isBst = true;
		result.minVal = INT_MAX;
		result.maxVal = INT_MIN;
		return result;
	}

	Info leftInfo = largestBSTSubtreeHelper(root->left, maxHeight);
	Info rightInfo = largestBSTSubtreeHelper(root->right, maxHeight);

	Info currentNodeInfo; 
	currentNodeInfo.height = max(leftInfo.height, rightInfo.height) + 1;

	if(leftInfo.isBst && rightInfo.isBst && root->data > leftInfo.maxVal && root->data < rightInfo.minVal){
		currentNodeInfo.isBst = true;
		currentNodeInfo.minVal = min(leftInfo.minVal, root->data);
		currentNodeInfo.maxVal = max(rightInfo.maxVal, root->data);
		maxHeight = max(maxHeight, currentNodeInfo.height);
	} else {
		currentNodeInfo.isBst = false;
	}

	return currentNodeInfo;
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
	int maxHeight;
	largestBSTSubtreeHelper(root, maxHeight);

	return maxHeight;
}


