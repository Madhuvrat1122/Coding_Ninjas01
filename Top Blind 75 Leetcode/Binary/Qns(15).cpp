// Problem:- https://leetcode.com/problems/reverse-bits/description/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        for (int i = 0; i < 32; i++){
            uint32_t lastbit = n & 1;
            // do left shift for creating a space to put the new bit to the right most position
            reversed <<= 1;
            // add the bit in the result
            reversed |= lastbit;
            // go to next bit
            n >>= 1;
        }
        return reversed;
    }
};
