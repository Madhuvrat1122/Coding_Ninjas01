// Problem:- https://leetcode.com/problems/sum-of-two-integers/submissions/1445480023/
// Solution:- https://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/
// Solution:- https://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/
class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int carry = (a & b)<<1; // carry
            a = a ^ b;  // (sum without carry)
            b = carry;
        }
        return a;
    }
};
