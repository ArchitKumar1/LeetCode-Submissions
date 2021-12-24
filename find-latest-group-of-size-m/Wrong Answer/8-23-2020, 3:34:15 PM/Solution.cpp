// https://leetcode.com/problems/find-latest-group-of-size-m

class Solution {
public:
    
    vector<int> par,sz,val;
    vector<set<int>> pos;
    int ans = -1;
    int m;
    int n;
    
    int f(int v){
        return (par[v] == v ? v : par[v] = f(par[v]));
    }
    void merge(int a,int b,int i,int type){
        
        cout << a << " " << b << endl;
        a = f(a);
        b = f(b);
        
        cout << a << " " << b << endl;
        int sa = sz[a];
        int sb = sz[b];
        
        cout << sz[a] << " " << sz[b] << endl;
        
         
        
        if(a > b){
            swap(a,b);
        }
        sz[a] += sz[b] + type;
        par[b] =a;
        
        pos[sz[a]].insert(a); 
        cout << sz[a]  << " " << a << endl;
        cout << "done" << endl;
        
    }
    bool valid(int i){
        return i>=0 && i<n && val[i] == 1;
    }
    int findLatestStep(vector<int>& arr, int m) {
        
        this->m = m;
        n = arr.size();
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
            
            if(valid(p-1) && valid(p+1)){
                merge(p-1,p+1,i,1);
            }
            else if(valid(p-1)){
                merge(p,p-1,i,0);
                
            }else if(valid(p+1)){
                merge(p,p+1,i,0);
                    
            }
        }
        return ans;
        
    }
};