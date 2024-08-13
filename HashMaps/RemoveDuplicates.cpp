#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> removeDuplicate(int* arr, int n){
    vector<int> unique;
    unordered_map<int, bool> seen;
    for(int i=0; i<n; i++){
        if(seen.count(arr[i]) > 0) {
            continue;
        }
        seen[arr[i]] = true;
        unique.push_back(arr[i]);
    }
    
    return unique;
}
int main()
{
    int arr[] = {1,2,3,3,2,1,5,6,4,5,6};
    int size = 11;
    vector<int> res = removeDuplicate(arr, size);
    // print result;
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    
    return 0;
}
