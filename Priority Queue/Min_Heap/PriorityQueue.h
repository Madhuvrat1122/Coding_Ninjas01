#include<vector>
using namespace std;
// It is also same as heap sort
// Time complexity = O(nlogn)
// Space complexity = O(n)
// implementing Min-Heap, Max-Heap will be same except minor logic change in upheapify. 
class PriorityQueue {
  vector<int> pq;
  
  public:
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty()){
            return -1;
        }
        return pq[0];
    }
    void insert(int data){
        pq.push_back(data);
        // up heapify
        int childIndex = pq.size()-1;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            if(pq[childIndex] < pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
                childIndex = parentIndex;
            }
            else{
                break;
            }
        }
    }
    int deleteMin(){
        if(isEmpty()){
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1]; // copying the last element with root
        pq.pop_back(); // removing the last element
        // down-heapify
       int parentIndex = 0;
       int leftIndex = 2*parentIndex + 1;
       int rightIndex = 2*parentIndex + 2;
       while(leftIndex < pq.size()){
           int minIndex = parentIndex;
           if(pq[leftIndex]< pq[minIndex]){
               minIndex = leftIndex;
           }
           if(rightIndex < pq.size() && pq[rightIndex] < pq[minIndex]){
               minIndex = rightIndex;
           }
           if(minIndex == parentIndex){
               break;
           }

           int temp = pq[minIndex];
           pq[minIndex] = pq[parentIndex];
           pq[parentIndex] = temp;
           
            parentIndex = minIndex;
            leftIndex = 2*parentIndex + 1;
            rightIndex = 2*parentIndex + 2;
       }

        return ans;
    }
};
