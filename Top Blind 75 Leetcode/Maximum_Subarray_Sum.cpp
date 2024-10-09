// Problem Url :- https://leetcode.com/problems/maximum-subarray/description/
int maxSubArray(vector<int>& nums) {
    //kadanes Algorightm
    // solution url :- https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i=0; i<nums.size(); i++) {
        sum += nums[i];

        if(maxSum < sum) maxSum = sum;
        if(sum < 0) sum = 0;
    }

    return maxSum;
}
