#include<iostream>
using namespace std;
template<typename T>
class QueueUsingDynamicArray {
  T *data;
  int firstIndex;
  int nextIndex;
  int capacity;
  int size;
  public:
    QueueUsingDynamicArray(){
        data = new T[5];
        firstIndex = -1;
        nextIndex = 0;
        capacity = 5;
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
        // checking if Queue is already Full Then create new array of double size
        if(size == capacity){
            T *newData = new T[2*capacity];
            // Copy the old element in right order
            int j=0;
            for(int i=firstIndex; i<capacity; i++){
                newData[j] = data[i];
                j++;
            }
            for(int i=0; i<firstIndex; i++){
                newData[j] = data[i];
                j++;
            }
            // deallocate the old array memory
            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
            // cout<<"Queue is Full!"<<endl;
            // return;
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
