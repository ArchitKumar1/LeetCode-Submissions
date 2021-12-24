// https://leetcode.com/problems/maximum-length-of-pair-chain

class Solution {
public:
    static bool comp(vector<int> & A,vector<int> & B){
        return A[1] < B[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        int ans = 0;
        int MIN = INT_MIN;
        
        for(auto p : pairs){
            if(p[0] > MIN){
                ++ans;
                MIN = p[1];
            }
        }
        return ans;
    }
};