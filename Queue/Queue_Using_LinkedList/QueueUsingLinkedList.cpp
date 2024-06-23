#include<iostream>
using namespace std;
template<typename T>
class Node{
    public:
        Node<T> *next;  
        T data;
        Node(T data){
          this->data = data;
          next = NULL;
        }
};
template<typename T>
class QueueUsingLinkedList {
  Node<T> *head;
  Node<T> *tail;
  int size;
  public:
    QueueUsingLinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    // Get Size of Queue
    int getSize(){
        return size;
    }
    // Check Queue status
    bool isEmpty(){
        return head == NULL;
    }
    //get first elememt
    T front(){
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }
        return head->data;
    }
    // Insert Element Into Queue
    void Enqueue(T element){
        // creating new element
        Node<T> *newNode = new Node<T>(element);
        // If we are pushing the first elememt
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
         tail->next = newNode;
         tail = newNode;
        }
        size++;
    }
    // Delete element from Queue
    T Dequeue(){
        if(isEmpty()){
            cout<<"Queue is Aleady Empty!!"<<endl;
            return 0;
        }
        T res = head->data;
        head = head->next;
        size--;
        return res;
    }
};
