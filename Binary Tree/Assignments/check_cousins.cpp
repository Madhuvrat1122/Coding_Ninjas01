// Problem statement
// Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are cousins of each other or not. Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.

// Do it in O(n).

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= N <= 10^5

// Sample Input :
// 5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
// 2
// 4
// Sample Output :
// true

bool isSibling(BinaryTreeNode<int>* root, int p, int q){
    if(root == NULL){
        return false;
    }

    if(root->left && root->right){
        if(root->left->data == p && root->right->data == q){
            return true;
        }
        if (root->left->data == q && root->right->data == p) {
            return true;
        }
    }

    return isSibling(root->left, p, q) || isSibling(root->right, p, q);

}
int level(BinaryTreeNode<int>* root, int p, int curlevel){
    if(root == NULL){
        return 0;
    }
    if(root->data == p){
        return curlevel;
    }
    int l = level(root->left, p, curlevel+1);
    if(l!=0){
        return l;
    }

    return level(root->right, p, curlevel+1);
}
bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    if(level(root, p, 1) == level(root, q, 1) && !isSibling(root, p, q)){
        return true;
    } else {
        return false;
    }

}
