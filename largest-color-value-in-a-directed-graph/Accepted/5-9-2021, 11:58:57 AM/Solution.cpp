// https://leetcode.com/problems/largest-color-value-in-a-directed-graph

namespace y_combinator_namespace{
    template<class Fun>
    class y_combinator_result {
        Fun fun_;
    public:
        template<class T>
        explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

        template<class ...Args>
        decltype(auto) operator()(Args &&...args) {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };

    template<class Fun>
    decltype(auto) y_combinator(Fun &&fun) {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }
}
using namespace y_combinator_namespace;


const int MAXN = 1e5+1;

class Solution {
public:
    int dp[MAXN][26];
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int N = colors.size();
        vector<int> G[N];
        vector<int> col(N,-1);
        
        bool cycle = 0;
        for(auto x : edges){
            G[x[0]].push_back(x[1]); 
        }
        
        auto dfs = y_combinator([&](auto self,int s) -> void{            
            int color = colors[s] -'a';
            col[s] = 0;
            for(int c : G[s]){
                if(col[c] ==  0){
                    cycle = 1;
                }else if(col[c]== -1){
                    self(c);
                }
            }
            int ans = 0;
            for(int c : G[s]){
                for(int i = 0; i < 26;i++){
                    dp[s][i] = max(dp[s][i],dp[c][i]);
                }
            }
            dp[s][color]++;
            col[s] = 1;
        });
        
        for(int i = 0; i< N;i++){
            if(col[i] == -1) dfs(i);
        }
        int ans = 0;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < 26;j++){
                //if(j < 6) cout << i << " " << j << " " << dp[i][j] << endl;
                ans = max(ans,dp[i][j]);
            }
        }
        return cycle? -1 : ans;
    }
};