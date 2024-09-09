// Problem statement
// Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
//  5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// Output 1 : 
// 9 -> 3 -> 6 -> 5

vector<int>* longestPath(BinaryTreeNode<int>* root) {
    if(root == NULL){
        vector<int>* ans = new vector<int>();
        return ans;
    }

    vector<int>* leftPath = longestPath(root->left);
    vector<int>* rightPath = longestPath(root->right);
    if(leftPath->size() > rightPath->size()){
        leftPath->push_back(root->data);
    }
    else {
        rightPath->push_back(root->data);
    }

    return leftPath->size() > rightPath->size() ? leftPath : rightPath;
}
