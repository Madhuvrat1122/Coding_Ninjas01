// Problem:- https://leetcode.com/problems/number-of-1-bits/description/
// Solution:- https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n!=0){
            count += n & 1; // add 1 to count if lsb is 1
            n >>= 1; // right shift the bits by 1 and check and next bit now
        }
        return count;
    }
};
