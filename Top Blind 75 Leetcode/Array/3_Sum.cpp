//Problem Url:- https://leetcode.com/problems/3sum/description/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> resSet;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    vector<int> curr = {nums[i], nums[j], nums[k]};
                    resSet.insert(curr);
                    j++;
                    k--;
                }
                else if(sum > 0){
                    k--;
                }
                else {
                    j++;
                }
            }
        }

        vector<vector<int>> res(resSet.begin(), resSet.end());
        return res;
    }
};
