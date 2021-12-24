// https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int l, int r) {
        vector<int> v(100);
        for(auto x : ranges){
            int a = x[0],b=x[1];
            for(int k = a;k <= b;k++){
                v[k]=1;
            }
        }
        bool ans = 1;
        for(int k = l;k <= r;k++){
            if(v[k]==0)ans=0;
        }
        return ans;
    }
};