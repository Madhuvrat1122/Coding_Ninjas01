// Problem:- https://leetcode.com/problems/missing-number/submissions/1447560410/
// solution:- https://www.geeksforgeeks.org/find-the-missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0, n = nums.size();
        // calculate xor of all array elements
        for(int i=0; i<n; i++){
            xor1 ^= nums[i];
        }
        // calculate xor of all from 1 to n
        for(int i=1; i<=n; i++){
            xor2 ^= i;
        }
        return xor2 ^ xor1;
    }
};
