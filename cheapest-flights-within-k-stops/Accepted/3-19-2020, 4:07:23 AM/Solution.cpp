// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    struct node{
        int from,to,cnt,tcost;
    };
    int findCheapestPrice(int n, vector<vector<int>>& fl, int src, int dst, int K) {
        vector<vector<pair<int,int>>> all(n);
        for(vector v : fl){
            all[v[0]].emplace_back(v[1],v[2]);
        }
        vector<int> least(n,INT_MAX);
        queue<node>qq;
        int cost = INT_MAX;
        qq.push({0,src,0,0});
        while(qq.size()){
            node temp = qq.front();qq.pop();
            if(temp.cnt > K+1) continue;
            if(least[temp.to] < temp.tcost){
                continue;
            }
            least[temp.to] = temp.tcost;
            if(temp.to == dst){
                cost = min(cost,temp.tcost);
            }
            for(pair<int,int> p :all[temp.to] ){
                qq.push({temp.to,p.first,temp.cnt + 1,temp.tcost+p.second});
            }
        }
        return (cost !=INT_MAX ? cost : -1);
    }
};