// https://leetcode.com/problems/min-cost-to-connect-all-points

class Solution {
public:
    
    struct edge{
        int x,y,cost;
        bool operator < (const edge &e) const{
            return cost < e.cost;
        }
    };
    vector<edge> all;
    vector<int> par;
    
    int f(int v){
        return (par[v] == v ? v : par[v] = f(par[v]));
    }
    void merge(int a,int b){
        a =f(a),b= f(b);
        par[a] = b;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        par.assign(n,0);
        
        for(int i = 0;i<n;i++){
            par[i] = i;
            for(int j =i+1;j<n;j++){
                edge a;
                a.x = i,a.y = j;a.cost= abs(points[i][0] -points[j][0]) + abs(points[i][1] -points[j][1]);
                all.push_back(a);
            }
        }
        int cost = 0;
        sort(all.begin(),all.end());
        for(auto e : all){
            if(f(e.x) != f(e.y)){
                cost += e.cost;
                merge(e.x,e.y);
            }
        }
        return cost;
    }
};