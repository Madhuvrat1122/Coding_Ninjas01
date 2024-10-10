// Problem:- https://leetcode.com/problems/maximum-product-subarray/submissions/1417660587/
// Solution:- https://www.geeksforgeeks.org/maximum-product-subarray/
// Traverse In both direction
int maxProduct(vector<int>& nums) {
    int maxProduct = INT_MIN;
    int lefttoright = 1;
    int righttoleft = 1;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(lefttoright == 0) lefttoright = 1;
        if(righttoleft == 0) righttoleft = 1;
        lefttoright = lefttoright*nums[i];
        righttoleft = righttoleft*nums[n-i-1];
        maxProduct = max(maxProduct, max(lefttoright, righttoleft));
    }
    return maxProduct;
}
