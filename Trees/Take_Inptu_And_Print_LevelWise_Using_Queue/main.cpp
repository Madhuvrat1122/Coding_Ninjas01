#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;
// print Tree Level Wise
void printTreeLevelWise(TreeNode<int>* root){
    // Edge Case Not base Case
    if(root == NULL){
        return;
    }
    
    // Queue
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode<int>* front = q.front();
        q.pop();
        
        cout<<front->data<<":";
        
        // print all children
        for(int i=0; i<front->children.size(); i++){
            cout<<front->children[i]->data<<",";
            q.push(front->children[i]);
        }
        cout<<endl;
    }
}
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
int main()
{
    // Take Input Level Wise (First Take input of all children for the current TreeNode then go deeper)
    TreeNode<int>* root = TakeInputLevelWise();
    
    // print Tree Level Wise
    printTreeLevelWise(root);

    return 0;
}

// Output Without Level Wise
/*
Enter Root Data:- 
1
Enter No. Of Children For 1:- 
3
Enter 0th child for 1:- 
2
Enter 1th child for 1:- 
3
Enter 2th child for 1:- 
4
Enter No. Of Children For 2:- 
2
Enter 0th child for 2:- 
5
Enter 1th child for 2:- 
6
Enter No. Of Children For 3:- 
1
Enter 0th child for 3:- 
7
Enter No. Of Children For 4:- 
1
Enter 0th child for 4:- 
8
Enter No. Of Children For 5:- 
0
Enter No. Of Children For 6:- 
0
Enter No. Of Children For 7:- 
0
Enter No. Of Children For 8:- 
0
1:2,3,4,
2:5,6,
5:
6:
3:7,
7:
4:8,
8:
*/

//Output Level Wise
/*
Enter Root Data:- 
1
Enter No. Of Children For 1:- 
3
Enter 0th child for 1:- 
2
Enter 1th child for 1:- 
3
Enter 2th child for 1:- 
4
Enter No. Of Children For 2:- 
2
Enter 0th child for 2:- 
5
Enter 1th child for 2:- 
6
Enter No. Of Children For 3:- 
1
Enter 0th child for 3:- 
7
Enter No. Of Children For 4:- 
1
Enter 0th child for 4:- 
8
Enter No. Of Children For 5:- 
0
Enter No. Of Children For 6:- 
0
Enter No. Of Children For 7:- 
0
Enter No. Of Children For 8:- 
0
1:2,3,4,
2:5,6,
3:7,
4:8,
5:
6:
7:
8:
*/
