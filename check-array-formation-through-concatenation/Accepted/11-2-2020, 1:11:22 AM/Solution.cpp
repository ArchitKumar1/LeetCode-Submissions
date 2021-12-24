// https://leetcode.com/problems/check-array-formation-through-concatenation

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        map<vector<int>,int> m1;
        int n = arr.size();
        vector<int> dp(n+1,0);
        
        for(auto x : pieces){
            m1[x] += 1;
        }
        dp[0] = 1;
        for(int i =0 ;i<=n;i++){
            vector<int> curr;
            if(dp[i] == 0) continue;
            for(int j = i+1;j<=n;j++){
                curr.push_back(arr[j-1]);
                if(m1[curr] > 0){
                    dp[j] = 1;
                }
            }
        }
        return dp[n];
    }
};