#include<iostream>
using namespace std;
template<typename T>
class QueueUsingArray {
  T *data;
  int firstIndex;
  int nextIndex;
  int capacity;
  int size;
  public:
    QueueUsingArray(int size){
        data = new T[size];
        firstIndex = -1;
        nextIndex = 0;
        capacity = size;
        size = 0;
    }
    // Get Size of Queue
    int getSize(){
        return size;
    }
    // Check Queue status
    bool isEmpty(){
        return size==0;
    }
    //get first elememt
    T front(){
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
    // Insert Element Into Queue
    void Enqueue(T element){
        // checking if Queue is already Full
        if(size == capacity){
            cout<<"Queue is Full!"<<endl;
            return;
        }
        // If we are pushing the first elememt
        if(firstIndex == -1){
            firstIndex = 0;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        size++;
    }
    // Delete Front element from Queue
    T Dequeue(){
        if(isEmpty()){
            cout<<"Queue is Aleady Empty!!"<<endl;
            return 0;
        }
        T res = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if(size == 0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return res;
    }
};
