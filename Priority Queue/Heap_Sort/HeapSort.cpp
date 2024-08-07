void heapSort(int arr[], int n) {

    // Step 1. Converting Array Into Heap
    for(int i=1; i<n; i++){
        int childIndex = i;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            if(arr[childIndex] < arr[parentIndex]){
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
                childIndex = parentIndex;
            }
            else{
                break;
            }
        }
    }

    // Apply Heap Deletion to sorting the heap
    int size = n;
    while(size > 1){
        int temp = arr[0];
        arr[0] = arr[size-1];
        arr[size-1] = temp;
        // to avoid the last element of heap since its deleted
        size--;

        int parentIndex = 0;
        int leftIndex = 2*parentIndex + 1;
        int rightIndex = 2*parentIndex + 2;
        while(leftIndex < size){
            int minIndex = parentIndex;
            if(arr[leftIndex]< arr[minIndex]){
                minIndex = leftIndex;
            }
            if(rightIndex < size && arr[rightIndex] < arr[minIndex]){
                minIndex = rightIndex;
            }
            if(minIndex == parentIndex){
                break;
            }

            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            
            parentIndex = minIndex;
            leftIndex = 2*parentIndex + 1;
            rightIndex = 2*parentIndex + 2;
        }
    }
}
}
