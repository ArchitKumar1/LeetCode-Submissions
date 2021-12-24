// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    struct node{
        int f,t,cnt,tcost;
    };
    int findCheapestPrice(int n, vector<vector<int>>& fl, int src, int dst, int K) {
        vector<vector<pair<int,int>>> all(n);
        for(vector v : fl){
            all[v[0]].emplace_back(v[1],v[2]);
        }
        vector<int> least(n,INT_MAX);
        vector<int> vis(n,0);
        queue<node>qq;
        int cost = INT_MAX;
        qq.push({0,src,0,0});
        
        while(qq.size()){
            node temp = qq.front();qq.pop();
            // if(vis[temp.t]  == 1)continue;
            // vis[temp.t] = 1;
            if(temp.cnt > K+1) continue;
            if(least[temp.t] < temp.tcost){
                continue;
            }
            least[temp.t] = temp.tcost;
            if(temp.t == dst){
                cost = min(cost,temp.tcost);
            }
            for(pair<int,int> p :all[temp.t] ){
                qq.push({temp.t,p.first,temp.cnt + 1,temp.tcost+p.second});
            }
        }
        return (cost !=INT_MAX ? cost : -1);
    }
};