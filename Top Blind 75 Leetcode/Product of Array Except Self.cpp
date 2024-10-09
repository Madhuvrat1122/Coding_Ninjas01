// Problem URL:- https://leetcode.com/problems/product-of-array-except-self/description/
// Approach:- Use Prefix and Suffix Product of elements
// Complexity:- O(n)
vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0), suffix(n,0), result(n,0);
        // fill prefix product array
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1]*nums[i];
            suffix[n-i-1] = suffix[n-i]*nums[n-i-1];
        }
        // calculate the product of array except self
        result[0] = suffix[1]; // no prefix left
        result[n-1] = prefix[n-2]; // no suffix left
        for(int i=1; i<n-1; i++){
            result[i] = prefix[i-1]*suffix[i+1];
        }
        
        return result;
}
