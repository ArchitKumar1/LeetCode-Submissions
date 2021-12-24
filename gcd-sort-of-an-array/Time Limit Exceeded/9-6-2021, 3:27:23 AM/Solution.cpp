// https://leetcode.com/problems/gcd-sort-of-an-array


class dsu {
    public:
    
};
class Solution {
public:

    vector<int> par;
    vector<int> size;
    int n;
    void dsu(int _n) {
        n = _n;
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        size.assign(n, 1);
    } 
    inline int get(int x) {
        return (x == par[x] ? x : (par[x] = get(par[x])));
    }
    inline bool merge(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            if(size[x] < size[y]) swap(x,y);
            par[y] = x;
            size[x] += size[y];
            return true;
        }
        return false;
    }
    bool gcdSort(vector<int>& nums) {
        const int N = 1e5+1;
        int n = nums.size();
        unordered_map<int,int> m1;
        m1.reserve(N);
        for(int c : nums) m1[c]++;
        dsu(N);
        vector<int> vis(N,0);
        bool ans = true;
        for(int i = 2;i < N;i++){
            if(vis[i] != 0) continue;
            for(int j = i;j < N;j+= i){
                vis[j] = 1;
                if(m1[j]) merge(i,j);
                // if(m1[j]) facts[i].push_back(j);
            }
        }
        // for(int i = 2;i < N;i++){
        //     for(int j = 0;j+1<facts[i].size();j++){
        //         d.merge(facts[i][j],facts[i][j+1]);
        //     }
        // }
        vector<int> snums = nums;
        sort(snums.begin(),snums.end());
        
        // for(int i = 0;i < n;i++){
        //     int p = d.get(nums[i]);
        //     // cout << i << " " << nums[i] << " "<< " "<< p << endl;
        //     // G[p].push_back(i);
        // }
        
        for(int i = 0;i < n;i++){
            if(get(nums[i])!= get(snums[i])) return false;
        }
        return true;
    }
};