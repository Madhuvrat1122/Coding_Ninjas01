#include <iostream>
using namespace std;
class stackUsingArray {
    int *data;
    int capacity;
    int top;
    public:
        stackUsingArray(int totalsize){
            data = new int[totalsize];
            top = 0;
            capacity = totalsize;
        }
        // get the size of stack
        int size() {
            return top;
        }
        // push into the stack
        void push(int element){
            if(top == capacity){
                cout<<"Stack Overflow!!"<<endl;
                return;
            }
            data[top] = element;
            top++;
        }
        // check stack empty or not
        bool isEmpty(){
            return top == 0;
        }
        // delete element from stack;
        int pop(){ 
            if(isEmpty()){
                cout<<"stack Underflow"<<endl;
                return -1;
            }
            top--;
            return data[top];
        }
        //get the top element
        int topElement(){
            if(isEmpty()){
                cout<<"Stack is empty!!"<<endl;
                return -1;
            }
            return data[top-1];
        }
};