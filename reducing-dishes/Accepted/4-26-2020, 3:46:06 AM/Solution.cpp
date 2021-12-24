// https://leetcode.com/problems/reducing-dishes

class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int n = s.size();
        int ans =0 ;
        for(int i =0;i<n;i++){
            int temp = 0;
            int cnt = 1;
            for(int j = i;j<n;j++){
                temp += s[j]*cnt;
                cnt++;
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};