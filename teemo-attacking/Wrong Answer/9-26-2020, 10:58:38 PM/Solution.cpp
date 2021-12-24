// https://leetcode.com/problems/teemo-attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        sort(t.begin(),t.end());
        int ans = d;
        int time = t[0];
        int n = t.size();
        for(int i = 1;i<n;i++){
            int diff = t[i] - time;
            if(diff == d){
                ans += d;
            }else if(diff < d){
                ans += d;
                ans -= diff;
            }else{
                ans += d;
            }
            time = t[i];
        }
        return ans;
    }
};