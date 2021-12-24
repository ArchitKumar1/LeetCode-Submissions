// https://leetcode.com/problems/gcd-sort-of-an-array

class dsu {
    public:
    vector<int> par;
    int n;
    dsu(int _n) : n(_n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    } 
    inline int get(int x) {
        return (x == par[x] ? x : (par[x] = get(par[x])));
    }
    inline bool merge(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            par[x] = y;
            return true;
        }
        return false;
    }
};
class Solution {
public:

    bool gcdSort(vector<int>& nums) {
        const int N = 1e5+1;
        int n = nums.size();
        dsu d(N);
        unordered_map<int,int> m1;
        vector<vector<int>> G1(N);
        
        for(int i = 0;i < n;i++){
            G1[nums[i]].push_back(i);
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j+1<G1[i].size();j++){
                d.merge(G1[i][j],G1[i][j+1]);
            }
        }
        for(int i = 0;i < n;i++) m1[nums[i]] = i+1;
        for(int i = 2;i < N;i++){
            for(int j = 2*i;j < N;j+= i){
                if(m1[i] && m1[j]) d.merge(m1[i]-1,m1[j]-1);
            }
        }
        vector<int> snums = nums;
        sort(snums.begin(),snums.end());
        vector<vector<int>> G(n);
        
        for(int i = 0;i < n;i++){
            int p = d.get(i);
            cout << i << " "<< p << endl;
            G[p].push_back(i);
        }
        bool ans = true;
        for(int i = 0;i < n;i++){
            vector<int> curr;
            vector<int> old;
            for(int idx : G[i]) old.push_back(nums[idx]);
            for(int idx : G[i]) curr.push_back(snums[idx]);
            sort(old.begin(),old.end());
            sort(curr.begin(),curr.end());
            if(old!=curr)ans= false;
        }
        return ans;
    }
};