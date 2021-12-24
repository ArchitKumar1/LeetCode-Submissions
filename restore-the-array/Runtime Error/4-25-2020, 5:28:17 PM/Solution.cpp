// https://leetcode.com/problems/restore-the-array

class Solution {
    #define VI vector<int> 
    #define LL long long int
    #define mod = 1e9+7;
    
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        
        VI dp(n+1,0);
        dp[0] = 1;
        
        int digi = to_string(k).size();
        cout << digi << " " << k << endl;
        
        for(int i = 0;i<n;i++){
            for(int d = 0;d<digi;d++){
                if(i-d>=0){
                    string st = s.substr(i-d,d+1);
                    LL temp =  stoll(st);
                    if(st[0]!= '0' && temp <= k){
                    cout << i << "  " << st << " " << temp << " " << d+1 << endl;                        
                        dp[i+1] += dp[i+1-d-1];
                    }
                }
            }
        }
        return dp[n];
    }
};