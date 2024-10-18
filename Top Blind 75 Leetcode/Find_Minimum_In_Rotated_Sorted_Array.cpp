// Problem URL:- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findPivot(vector<int>& nums){
        if(nums.size()==1){
            return 0;
        }
        else if(nums.size()==2){
            return nums[0] > nums[1] ? 1 : 0;
        }
        int low = 0, high = nums.size()-1;
        int ans = 0;
        while(low <= high){
            int mid = (low+high)/2;
            if(mid > 0 && nums[mid] < nums[mid-1]){
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
    int findMin(vector<int>& nums) {
        int pivot = findPivot(nums);
        return nums[pivot];
    }
};
