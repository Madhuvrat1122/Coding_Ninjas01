
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;
int main()
{
    BST b;
    b.insertData(50);
    b.insertData(45);
    b.insertData(58);
    b.insertData(42);
    b.insertData(48);
    b.insertData(55);
    b.insertData(60);
    b.insertData(54);
    b.insertData(56);
    b.insertData(59);
    b.insertData(65);
    b.insertData(57);
    
    b.printTree();
    
    //delete 57
    // cout<<"After Delete 57:- "<<endl;
    // b.deleteData(57);
    // b.printTree();
    
    //delete 57
    // cout<<"After Delete 56:- "<<endl;
    // b.deleteData(56);
    // b.printTree();
    
    //delete 55
    cout<<"After Delete 55:- "<<endl;
    b.deleteData(55);
    b.printTree();

    return 0;
}





