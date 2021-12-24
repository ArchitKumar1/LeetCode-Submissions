// https://leetcode.com/problems/largest-component-size-by-common-factor

class Solution {
public:
    vector<int> par,size;
    int find(int v){
        if(par[v] == v){
            return v;
        }else{
            return par[v] = find(par[v]);
        }
    }
    void merge(int a,int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(size[a] < size[b]) swap(a,b);
        par[b] = a;
        size[a] += size[b];
    }
    int largestComponentSize(vector<int>& A) {       
        int N = 1e5+10;

        vector<vector<int>> G(N);
        int a = A.size();
        par.resize(N);
        for(int i = 0;i<N;i++){
            par[i] = i;
        }
        size.assign(N,1);
        
        for(int c : A){
            
            for(int i = 1;i*i<=c;i++){
                if(c%i == 0){
                    G[i].push_back(c);
                    if(c/i != i){
                        G[i/c].push_back(c);
                    }
                }
            }
        }
        for(int i = 2;i<N;i++){
            for(int j = 0;j+1<G[i].size(); j++){
                merge(G[i][j],G[i][j+1]);
            }
        
        }
        int ans = 0;
        for(int i = 1;i<N;i++){
            if(size[i]>=1){
                ans = max(ans,find(i));
            }
        }
        return ans;
        
    }
};