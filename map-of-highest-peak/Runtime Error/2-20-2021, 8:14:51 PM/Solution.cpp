// https://leetcode.com/problems/map-of-highest-peak

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                if(isWater[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        
        int H = 0;
        while(q.size()){
            int S = q.size();

            for(int s = 0;s<S;s++){
                pair<int,int> top = q.front();
                q.pop();
                int i = top.first;
                int j = top.second;

                if(vis[i][j] == 1) continue;
                vis[i][j] = 1;
                ans[i][j] = H;
                for(int k=0;k<4;k++){
                    int I = i+dx[k],J = j+dy[k];
                    if( I<n && J<m && I>=0 && J>=0){
                        q.push({I,J});
                    }
                }
            }
            H++;
        }
        return ans;
    }
};