// https://leetcode.com/problems/n-repeated-element-in-size-2n-array

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int,int> m1;
        int ans = 0;
        for(auto c : A)
            m1[c]++;
        for(auto it : m1){
            if(it.second == A.size() /2){
                ans = it.first;
            } 
        }
        return ans;
    }
};