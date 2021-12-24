// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    
    vector<int> par;
    vector<int> size;
    int get(int v){
        return (par[v] == v ? v : get(par[v]));
    }
    void merge(int a,int b){
        a = get(a);
        b = get(b);
        if(a ==b) return ;
        if(size[a] < size[b]) swap(a,b);
        par[b] = a;
        size[a] += size[b];
        size[b] = 0;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size() + 1;
        par.assign(n,0);
        size.assign(n,1);
        for(int i = 0;i<n;i++){
            par[i] = i;
        }
        int m = M.size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<m;j++){
                if(M[i][j] == 1){
                    merge(i,j);
                }
            }
        }
        set<int> ans;
        for(int i = 0;i<m;i++){
            cout << get(i) << " " << size[get(i)] << endl;
            ans.insert(get(i));
        }
        return ans.size();
    }
};