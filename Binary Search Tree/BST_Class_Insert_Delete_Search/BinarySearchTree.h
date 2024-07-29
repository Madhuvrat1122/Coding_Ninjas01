#include "BinaryTreeNode.h"
using namespace std;
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
    
    BinaryTreeNode<int>* insertDataHelper(BinaryTreeNode<int>* root, int data){
        if(root == NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        // left side
        else if(root->data > data){
            root->left = insertDataHelper(root->left, data);
        }
        // right side
        else {
            root->right = insertDataHelper(root->right, data);
        }
        return root;
    }
    
    BinaryTreeNode<int>* deleteDataHelper(int data, BinaryTreeNode<int>* root){
        // empty tree
        if(root == NULL){
            return NULL;
        }
        // traverse in left
        else if(root->data > data){
            root->left = deleteDataHelper(data, root->left);
            return root;
        }
        // traverse in right
        else if(root->data < data){
            root->right = deleteDataHelper(data, root->right);
            return root;
        }
        else {
            // leaf node
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            // only left child 
            else if(root->right == NULL){
                BinaryTreeNode<int>* temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            // only right child
            else if(root->left == NULL){
                BinaryTreeNode<int>* temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            //both child exist
            // Approach:- replace root with minimum of right child OR replace root with maximum of left child
            else {
                // find minimum of right
                BinaryTreeNode<int>* minNode = root->right;
                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                int minData = minNode->data;
                root->data = minData;
                root->right = deleteDataHelper(minData, root->right);
                return root;
            }
        }
        
    }
    
    void printTreeHelper(BinaryTreeNode<int>* root){
        if(root == NULL){
            return;
        }
        cout<<root->data<<" : ";
        if(root->left){
            cout<<"L"<<root->left->data<<",";
        }
        if(root->right){
            cout<<"R"<<root->right->data;
        }
        cout<<endl;
        
        printTreeHelper(root->left);
        printTreeHelper(root->right);
    }
    
    public:
        BST(){
            root = NULL;
        }
        
        void insertData(int data){
            root = insertDataHelper(root, data);
        }
        
        void printTree(){
            printTreeHelper(root);
        }
        
        bool hasData(int data){
            return hasDataHelper(data, root);
        }
        
        void deleteData(int data){
            root = deleteDataHelper(data, root);
        }
        
        ~BST(){
            delete root;
        }
};
