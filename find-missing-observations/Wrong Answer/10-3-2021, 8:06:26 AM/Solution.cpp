// https://leetcode.com/problems/find-missing-observations

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total = 0;
        int m = rolls.size();
        for(int r : rolls) total += r;
        int totalsum = round((n+m) * mean);
        int left = totalsum - total;
        
        vector<int> dummy;
        if(left < 0) return dummy;
        if(left > 6*m ) return dummy;
        vector<int> ans(n,1);
        left -= n;
        
        for(int i = 0;i < n;i++){
            if(left <= 0) break;
            int a = 0;
            if( left > 5){
                a = 5;
            }else{
                a = left;
            }
            left -= a;
            ans[i] += a;
        }
        return ans;
    }
};