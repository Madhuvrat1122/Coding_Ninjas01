#include<iostream>
using namespace std;

template<typename T>
class Node {
    public:
    Node<T> *next;
    T data;
    Node(T element){
        this->data = element;
        next = NULL;
    }
};

// Stack Class
template<typename T>
class StackUsingLL {
    public:
    Node<T>* head;
    int size;
    
    StackUsingLL(){
        head = NULL;
        size = 0;
    }
    
    void push(T data){
        // creating new Node
        Node<T> *newNode = new Node<T>(data);
        if(head == NULL){
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        this->size++;
    }
    
    T pop(){
        this->size--;
        T ans = head->data;
        head = head->next;
        return ans;
    }
    
    T top(){
        return head->data;
    }
    
    int getSize(){
        return size;
    }
    
    bool isEmpty(){
        return size==0;
    }
};;
