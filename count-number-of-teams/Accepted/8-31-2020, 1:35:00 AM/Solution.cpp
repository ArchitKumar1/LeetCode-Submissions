// https://leetcode.com/problems/count-number-of-teams

class Solution {
public:
    int numTeams(vector<int>& r) {
        int n =r.size();
        
        int ans =0 ;
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(r[i] > r[j] && r[j] > r[k]) ans++;
                    if(r[k] > r[j] && r[j] > r[i]) ans++;
                }
            }
        }
        return ans;
    }
};