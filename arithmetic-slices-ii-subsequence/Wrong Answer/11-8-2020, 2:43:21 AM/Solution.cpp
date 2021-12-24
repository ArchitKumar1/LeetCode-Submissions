// https://leetcode.com/problems/arithmetic-slices-ii-subsequence

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        vector<int> diffs;
        
        
        int n = A.size();
        for(int i = 0;i+1<n;i++){
            diffs.push_back(A[i+1]-A[i]);
        }
        
        vector<int> dp(n,0);
        int ans = 0;
        for(int i = 1;i<n;i++){
            int curr = diffs[i-1];
            int c = dp[curr];
            cout << i << " " <<  curr << " " << dp[curr] << endl;
            ans += dp[curr];
            if(c == 1){
                dp[curr] = 1;
            }
            if(c == 2){
                dp[curr] += 1;
            }
            dp[curr]++;
            cout << dp[curr] << endl;
        }
//         2 2 2 2 
//         0 1 2 3 
        

        return ans;
    }
};