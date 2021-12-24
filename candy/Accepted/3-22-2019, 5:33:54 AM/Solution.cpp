// https://leetcode.com/problems/candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        int l = ratings.size(), ret = 0;
        vector<int> candy = vector(l, 1);
        
        for(int i=1; i<l; i++) if(ratings[i] > ratings[i-1]) candy[i] = candy[i-1]+1;
        for(int i=l-1; i>=1; i--) if(ratings[i-1] > ratings[i] && candy[i-1] <= candy[i]) candy[i-1] = candy[i]+1;
        for(int i=0; i<l; i++) ret += candy[i];
        
        return ret;
    }
};