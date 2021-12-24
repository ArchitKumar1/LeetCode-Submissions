// https://leetcode.com/problems/minimum-number-of-people-to-teach

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        const int N = 510;
        
        int knows[N][N];
        memset(knows,0,sizeof(knows));
        
        int m = languages.size();
        for(int i = 0;i<m;i++){
            for(auto x : languages[i]){
                knows[x][i] = 1;
            }
        }
        set<int> rem;
        
        for(auto x : friendships){
            int u = x[0],v = x[1];
            u--,v--;
            bool found = 0;
            for(int x : languages[u]){
                if(knows[x][v] == 1){
                    found = 1;
                }
            }
            if(!found){
               rem.insert(u);
               rem.insert(v);
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            int curr = 0;
            for(int c : rem){
                if(knows[i][c] != 1){
                    curr += 1;
                }
            }
            ans = min(ans,curr);
        }
        return ans;
    }
};