// Problem:- https://leetcode.com/problems/counting-bits/description/
class Solution {
public:
    int countsetbits(int a){
        int count = 0;
        while(a){
            count += a & 1;
            a >>= 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
            ans.push_back(countsetbits(i));
        }
        return ans;
    }
};
