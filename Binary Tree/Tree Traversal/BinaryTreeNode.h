template<typename T>
class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T>* left;
        BinaryTreeNode<T>* right;
        // Contructor
        BinaryTreeNode(T data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
        // Destructor
        ~BinaryTreeNode(){
            delete left;
            delete right;
        }
};
