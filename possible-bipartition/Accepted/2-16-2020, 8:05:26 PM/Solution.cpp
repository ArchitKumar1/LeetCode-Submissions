// https://leetcode.com/problems/possible-bipartition

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> color(N+1,-1);
        vector<vector<int>> edges(N+1);
        
        for(vector<int> a : dislikes){
            edges[a[0]].push_back(a[1]);
            edges[a[1]].push_back(a[0]);
        }
        bool ok = 1;
        queue<int> q;
        for(int i = 1;i<=N;i++){
            if(color[i] == -1){
                q.push(i);
                color[i] = 0;
                while(q.size()){
                    int s= q.front();
                    q.pop();
                    for(int c : edges[s]){
                        if(color[c] == -1){
                            color[c] = color[s] ^ 1;
                            q.push(c);
                        }else{
                            ok &= color[c]!= color[s];
                        }
                    }
                }
            }
        }
        return ok;
        
    }
};