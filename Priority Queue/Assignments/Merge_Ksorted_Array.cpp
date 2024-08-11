// Problem statement
// Given k no. of different size arrays, which are sorted individually (in ascending order). 
// You need to merge all the given arrays such that output array should be sorted (in ascending order).
// Hint : Use Heaps.
// Sample Input 1:
// 4
// 3
// 1 5 9
// 2
// 45 90
// 5
// 2 6 78 100 234
// 1
// 0
// Sample Output 1:
// 0 1 2 5 6 9 45 78 90 100 234

#include<queue>
class elementType {
    public:
    int value;
    int elementindex;
    int arrayindex;
    elementType(int v, int e, int a){
        this->value = v;
        this->elementindex = e;
        this->arrayindex = a;
    }
    // Overload the '>' operator to be used in the min-heap
    bool operator>(const elementType &other) const {
        return value > other.value;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    priority_queue<elementType, vector<elementType>, greater<elementType>> min_heap;

    // to store the output
    vector<int> output;

    // storing all arrays first element in the min heap
    for(int i=0; i<input.size(); i++){
        // edge case
        if(!input[i]->empty()){
            int val = (*input[i])[0];
            elementType obj1(val, 0, i);
            min_heap.push(obj1);
        }
    }

    while(!min_heap.empty()){
        // take the top element from heap and push it in the result array
        elementType obj2 = min_heap.top();
        min_heap.pop();
        output.push_back(obj2.value);

        //  Now the push the next element from the same array from which the last poped element belongs to.
        // obviously when if array is not empty
        if(obj2.elementindex+1 < input[obj2.arrayindex]->size()){
            int val1 = (*input[obj2.arrayindex])[obj2.elementindex+1];
            elementType obj3(val1, obj2.elementindex+1, obj2.arrayindex);
            min_heap.push(obj3);
        }
    }

    return output;
}
