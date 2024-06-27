#include <iostream>
using namespace std;
class Node {
    public:
        Node* next;
        Node* prev;
        int data;
        Node(int data){
            this->data = data;
            prev = NULL;
            next = NULL;
        }
};
class Deque {
    Node* front;
    Node* rear;
    int size;
    public:
    // Contructor
    Deque(int size){
        this->size = 0;
        front = NULL;
        rear = NULL;
    }
    // Empty Function
    bool isEmpty(){
        return size == 0;
    }
    // Insert Front
    void insertFront(int ele){
        Node *node = new Node(ele);
        if(isEmpty()){
            front = node;
            rear = node;
            size++;
            return;
        }
        node->next = front;
        front->prev = node;
        front = node;
        size++;
    }
    // Insert Rear
    void insertRear(int ele){
        Node *node = new Node(ele);
        if(isEmpty()){
            front = node;
            rear = node;
            size++;
            return;
        }
        rear->next = node;
        node->prev = rear;
        rear = node;
        size++;
    }
    // delete front
    void deleteFront(){
        if(isEmpty()){
            cout<<-1<<endl;
            return;
        }
        else if(size == 1){
            front = NULL;
            rear = NULL;
            size--;
            return;
        }
        front = front->next;
        size--;
    }
    // delete Rear
    void deleteRear(){
        if(isEmpty()){
            cout<<-1<<endl;
            return;
        }
        else if(front->next == NULL){
            front = NULL;
            rear = NULL;
            size--;
            return;
        }
        (rear->prev)->next = NULL;
        rear = rear->prev;
        size--;
    }
    //getFront
    int getFront(){
        if(front == NULL){
            return -1;
        }
        return front->data;
    }
    // getRear
    int getRear(){
        if(rear == NULL){
            return -1;
        }
        return rear->data;
    }

};
int main()
{
    //Dynamically
   Deque q(10);
   
   cout<<q.getFront()<<endl;
   q.insertFront(49);
   q.insertFront(64);   // 64->49
   q.insertRear(99);    // 64->49->99
   cout<<q.getFront()<<endl;
   cout<<q.getRear()<<endl;
   q.insertRear(32);  // 64->49>99->32
   q.deleteFront(); // 49->99->32
   cout<<q.getFront()<<endl;
   q.deleteRear(); // 49->99
   cout<<q.getRear()<<endl;
   q.insertFront(109); // 109->49->99
   q.insertRear(100); // 109->49->99->100
   cout<<q.getFront()<<endl;
   cout<<q.getRear()<<endl;
   q.insertFront(11);
   q.insertFront(99);
   q.insertFront(12); // 12->99->11->109->49->99->100
   q.insertRear(23); // 12->99->11->109->49->99->100->23
   q.insertFront(87); // 87->12->99->11->109->49->99->100->23
    q.insertRear(45); // 87->12->99->11->109->49->99->100->23->45X
    q.insertFront(123); //123->87->12->99->11->109->49->99->100->23->45
    q.deleteFront(); // 87->12->99->11->109->49->99->100->23->45
    cout<<q.getFront()<<endl;
   cout<<q.getRear()<<endl;
    return 0;
}

//  5 1 49 1 64 2 99 5 6 2 32 3 5 4 6 1 109 2 100 5 6 1 11 1 99 1 12 2 23 1 87 2 45 1 123 3 5 6 -1









