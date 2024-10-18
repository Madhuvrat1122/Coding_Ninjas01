// Problem URL:- 
// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int findPivot(vector<int>& nums){
        if(nums.size()==1) return 0;
        else if(nums.size()==2) return nums[0] > nums[1] ? 1 : 0;
        int ans = 0;
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(mid > 0 && nums[mid-1] > nums[mid]){
                ans = mid;
                break;
            }
            else if(nums[mid] > nums[0]){
                low = mid+1;
            }
            else {
                high = mid;
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        if(nums[pivot] == target) return pivot;

        int start = 0, end = nums.size()-1;
        if(pivot == 0){
            end = nums.size()-1;
        }
        else if(target >= nums[0]) {
            end = pivot;
        }
        else {
            start = pivot+1;
        }

        int ans = -1;
        while(start <= end){
            int mid = (start+end)/2;
            if(nums[mid] == target) {
                ans = mid;
                break;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }

        return ans;
    }
};
