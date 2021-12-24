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
        int l = n.size();
        map<pair<int,int>,int> m1;
        for(int i = l-1;i>0;i--){
            for(int j = 0;j<=9;j++){
                if(dp[i][j] > 0){
                    m1[{i,j}] = 1;
                    cout << i << " " << j << " " << dp[i][j] <<  endl;
                    ans += dp[i][j];
                }
            }
        }
        for(int i=0;i<l;i++){
             int f = n[i] - '0';
            for(int j =0 ;j<=9;j++){
                if(j < f){
                    ans += dp[l-i][j];
                    cout << i << " " << j << " " << dp[l-i][j] << endl;
                }else if(i== l-1 && j == f){
                     ans += dp[l-i][j];
                    cout << i << " " << j << " " << dp[l-i][j] << endl;
                    j =10;
                }
                else{
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