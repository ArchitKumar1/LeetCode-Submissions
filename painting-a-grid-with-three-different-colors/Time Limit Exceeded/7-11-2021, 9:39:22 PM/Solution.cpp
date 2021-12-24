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
        
        auto safe = [&](string mask1,string mask2){
            for(int i= 0;i < mask1.size();i++){
                if(mask1[i] == mask2[i]) return 0;
            }
            return 1;
        };
        comp("",m);
        int old = 0;
        int N = vs.size();
        vector<vector<int>> G(N);
        for(int i = 0;i < N;i++){
            for(int j = i+1;j < N;j++){
                if(safe(vs[i],vs[j])){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        map<string,int> dp;
        
        for(auto x : vs){
            cout << x << endl;
        }
        //base case 
        for(string s : vs) dp[s] = 1;
        
        for(int t = 2;t <= n;t++){
            map<string,int> ndp;
            for(int i = 0;i < vs.size();i++){
                for(int j : G[i]){
                    ndp[vs[j]] += dp[vs[i]];
                    ndp[vs[j]] %= M;
                }
            }
            swap(ndp,dp);             
        }
        int ans = 0 ;
        for(auto x : dp) ans+= x.second,ans %= M;
        
        return ans;
        
    }
};