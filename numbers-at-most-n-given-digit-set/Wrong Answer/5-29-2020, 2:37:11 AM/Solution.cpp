// https://leetcode.com/problems/numbers-at-most-n-given-digit-set

class Solution {
public:

    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int dp[11][11] ={0};
        for(string s : D){
            dp[1][s[0]-'0'] = 1;
        }
        int ans = 0;
        for(int i = 2;i<11;i++){
            for(string s : D){
                for(int j = 0;j<=9;j++){
                    dp[i][s[0]-'0'] += dp[i-1][j];
                }
            }
        }
       
        string n = to_string(N);
        reverse(n.begin(),n.end());
        int l = n.size();
        for(int i = l-1;i>0;i--){
            for(int j = 0;j<=9;j++){
                ans += dp[i][j];
            }
        }
        while(n.size() > 0){
            int f = n[n.size()-1] - '0';
            for(int j =0 ;j<=9;j++){
                if(j < f){
                    ans += dp[n.size()][j];
                }else if(n.size() == 1 && j == f){
                    ans += dp[n.size()][j];
                    n.erase(n.end()-1);
                    j =10;
                }
                else{
                    n.erase(n.end()-1);
                    j =10;
                }

            }
        }
        for(int i = 0;i<4;i++){
            for(int j =0;j<9;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return ans;
    }
};