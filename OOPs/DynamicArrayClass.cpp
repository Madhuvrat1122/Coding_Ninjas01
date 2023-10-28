#include <iostream>
using namespace std;
class DynamicArray {
    int *data, nextIndex, capacity;
    public:
    DynamicArray(){
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }
    // custom copy constructor
    DynamicArray(DynamicArray const &d){
        //this->data = d.data; // shallow copy - by default
        this->data = new int[d.capacity];
        for(int i=0; i<d.nextIndex; i++){
            this->data[i] = d.data[i];
        }
        this->capacity = d.capacity;
        this->nextIndex = d.nextIndex;
    }
    // custom assignment operator overload
    void operator=(DynamicArray const &d){
        //this->data = d.data; // shallow copy - by default
        this->data = new int[d.capacity];
        for(int i=0; i<d.nextIndex; i++){
            this->data[i] = d.data[i];
        }
        this->capacity = d.capacity;
        this->nextIndex = d.nextIndex;
    }
    void add(int element){
        if(nextIndex == capacity){
            int *nextData = new int[capacity*2];
            for(int i=0; i<capacity; i++){
                nextData[i] = data[i];
            }
            delete [] data;
            data = nextData;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    int get(int i) const {
        if(i < nextIndex){
            return data[i];
        }
        else{
            return -1;
        }
    }
    void getAll() const {
        for(int i=0; i<nextIndex; i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    void insert(int i, int element){
        if(i < nextIndex){
            data[i] = element;
        }
        else if(i==nextIndex){
            add(element);
        }
        else{
            return;
        }
    }
    int getSize() const {
        return nextIndex;
    }
    int getCapacity() const {
        return capacity;
    }
};
int main() {
    DynamicArray arr;
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.add(60);
    arr.add(70);
    // arr.getAll();
    // cout<<arr.get(2);
    arr.insert(2, 50); // at last
    // arr.getAll();
    // cout<<arr.getSize()<<endl;
    // cout<<arr.getCapacity();
    
    // In-Built copy constructor
    // DynamicArray arr1(arr);
    // arr.add(700);
    // arr1.getAll();
    // arr.getAll();
    
    // copy Assignment operator
    DynamicArray arr2;
    arr2 = arr;
    arr.add(700);
    arr.getAll();
    arr2.getAll();
    return 0;
}