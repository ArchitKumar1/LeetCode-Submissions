// https://leetcode.com/problems/find-latest-group-of-size-m

class Solution {
public:
    
    vector<int> par,sz,val;
    vector<set<int>> pos;
    int ans = 0;
    int m;
    
    int f(int v){
        return (par[v] == v ? v : par[v] = f(par[v]));
    }
    void merge(int a,int b,int i){
        
        cout << a << " " << b << endl;
        a = f(a);
        b = f(b);
        
        cout << a << " " << b << endl;
        int sa = sz[a];
        int sb = sz[b];
        
        cout << sz[a] << " " << sz[b] << endl;
        
         pos[sa].erase(a);
         if(sa == m && pos[sa].size() == 0) ans = i;
         pos[sb].erase(b);
         if(sb == m && pos[sb].size() == 0) ans = i;
        
        if(a > b){
            swap(a,b);
        }
        sz[a] += sz[b];
        sz[b] = 0;
        par[b] =a;
        
        pos[sz[a]].insert(a); 
        cout << sz[a]  << " " << a << endl;
        cout << "done" << endl;
        
    }
    int findLatestStep(vector<int>& arr, int m) {
        
        this->m = m;
        int n = arr.size();
        par.assign(n,0);
        sz.assign(n,0);
        pos.resize(m+n);
        val.assign(n+1,0);
        
        for(int i = 0;i<n;i++){
            par[i] = i;
        }
        
        for(int i =0;i<n;i++){
            
            int p = arr[i]-1;
            val[p] = 1;
            sz[p] = 1;
            pos[1].insert(p);
            if(p-1 >=0 && val[p-1]){
                merge(p-1,p,i);
            }
            if(p+1<n && val[p+1]){
                merge(p,p+1,i);
            }
        }
        return ans;
        
    }
};