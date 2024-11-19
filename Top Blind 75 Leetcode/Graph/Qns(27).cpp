// Problem Url:- 
// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    void add(int x, unordered_map<int, int>& parent, unordered_map<int, int>& setSize) {
        if(parent.find(x) == parent.end()){
            parent[x] = x;
            setSize[x] = 1;
        }
    }
    int find(int x, unordered_map<int, int>& parent){
        if(parent[x] != x){
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
    void unionSet(int x, int y, vector<int> &arr, unordered_map<int, int>& setSize, unordered_map<int, int>& parent){
        int rootX = find(x, parent);
        int rootY = find(y, parent);
        if(rootX != rootY){
            if(setSize[rootX] < setSize[rootY]){
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            setSize[rootX] += setSize[rootY];
        }
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> parent;
        unordered_map<int, int> setSize;
        for(int i=0; i<nums.size(); i++){
            add(nums[i], parent, setSize);
            if(parent.find(nums[i]-1) != parent.end()){
                unionSet(nums[i]-1, nums[i], nums, setSize, parent);
            }
            if(parent.find(nums[i]+1) != parent.end()){
                unionSet(nums[i]+1, nums[i], nums, setSize, parent);
            }
        }

        int maximumLen = 0;
        for(auto i : setSize){
            if(find(i.first, parent) == i.first){
                maximumLen = max(maximumLen, i.second);
            }
        }
        return maximumLen;
    }
};
