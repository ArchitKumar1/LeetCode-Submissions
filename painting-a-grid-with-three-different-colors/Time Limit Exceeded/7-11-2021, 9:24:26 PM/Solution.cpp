// https://leetcode.com/problems/painting-a-grid-with-three-different-colors

class Solution {
public:
    
    int colorTheGrid(int m, int n) {
        const int M = 1e9+7;
        vector<string> vs;
        
        function<void(string,int)> comp = [&](string s,int l) -> void{            
            if(l == 0) {
                vs.push_back(s);
                return;
            }
            vector<char> cols = {'R','G','B'};
            for(char c : cols){
                if(s.size() && s.back()==c) continue;
                comp(s+c,l-1);
            }
            return;
        };
        

        comp("",m);
        int old = 0;
        
        map<string,int> dp;
        
        // for(auto x : vs){
        //     cout << x << endl;
        // }
        cout << vs.size() << endl;
        //base case 
        for(string s : vs) dp[s] = 1;
        
        //CHECKING INTERMASK COMPATIBILITY
        
        map<pair<string,string>,int> safe;
        
        for(int i = 0;i < vs.size();i++){
            for(int j = 0;j < vs.size();j++){
                bool safer = 1;
                for(int k = 0;k < vs[i].size();k++){
                    if(vs[i][k] == vs[j][k]) safer = 0;
                }
                if(safer){
                    safe[{vs[i],vs[j]}] = safe[{vs[j],vs[i]}] = 1;
                }
            }
        }
        for(int t = 2;t <= n;t++){
            map<string,int> ndp;
            for(int i = 0;i < vs.size();i++){
                for(int j = 0;j < vs.size();j++){
                    if(safe[{vs[i],vs[j]}]){
                        ndp[vs[j]] += dp[vs[i]];
                        ndp[vs[j]] %= M;
                    }
                }
            }
            swap(ndp,dp);             
        }
        int ans = 0 ;
        for(auto x : dp) ans+= x.second,ans %= M;
        
        return ans;
        
    }
};