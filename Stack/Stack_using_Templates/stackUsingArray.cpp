#include <iostream>
using namespace std;
template<typename T>
class stackUsingArray {
    T *data;
    int capacity;
    int top;
    public:
        stackUsingArray(){
            data = new T[4];
            top = 0;
            capacity = 4;
        }
        // get the size of stack
        int size() {
            return top;
        }
        // push into the stack
        void push(T element){
            if(top == capacity){
                // cout<<"Stack Overflow!!"<<endl;
                // return;
                // Creating new array with double size
                T *newData = new T[capacity*2];
                // copying the old value in new array
                for(int i=0; i<capacity; i++){
                    newData[i] = data[i];
                }
                // dellocate the old array
                delete [] data;
                // assigning the new array
                data = newData;
                capacity *= 2;
            }
            data[top] = element;
            top++;
        }
        // check stack empty or not
        bool isEmpty(){
            return top == 0;
        }
        // delete element from stack;
        T pop(){ 
            if(isEmpty()){
                cout<<"stack Underflow"<<endl;
                return -1;
            }
            top--;
            return data[top];
        }
        //get the top element
        T topElement(){
            if(isEmpty()){
                cout<<"Stack is empty!!"<<endl;
                return -1;
            }
            return data[top-1];
        }
};
