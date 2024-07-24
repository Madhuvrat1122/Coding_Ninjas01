#include "BinaryTreeNode.h"
class BST {
    BinaryTreeNode<int>* root;
    
    bool hasDataHelper(int data, BinaryTreeNode<int>* root){
        if(root == NULL){
            return false;
        }
        else if(root->data == data){
            return true;
        }
        else if(root->data > data){
            return hasDataHelper(data, root->left);
        }
        else {
            return hasDataHelper(data, root->right);
        }
    }
    
    public:
        BST(){
            root = NULL;
        }
        
        void insertData(int data){
            
        }
        
        bool hasData(int data){
            return hasDataHelper(data, root);
        }
        
        void deleteData(int data){
            
        }
        
        ~BST(){
            delete root;
        }
}
