// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class Solution {
public:
    vector<int> par;
    int cnt;
    
    
    int get(int v){
        return v == par[v] ? v : par[v] = get(par[v]);
    }
    void merge(int a,int b){
        a = get(a);
        b = get(b);
        if(a != b){
            par[a] = b;
            cnt--;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n =stones.size();
        cnt = n;
        
        par.assign(n,0);
        
        for(int i = 0;i<n;i++){
            par[i] = i;
        }
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(stones[i][0] == stones[j][0] ||stones[i][1] == stones[j][1] ){
                    merge(i,j);
                }
            }
        }
        return n - cnt;
    }
};