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
        unordered_map<int,int> m1;
        for(int c : nums) m1[c]++;
        dsu d(N);
        vector<vector<int>> facts(N);
        vector<vector<int>> G(N);
        bool ans = true;
        for(int i = 2;i < N;i++){
            for(int j = i;j < N;j+= i){
                
                if(m1[j]) facts[i].push_back(j);
            }
        }
        for(int i = 2;i < N;i++){
            for(int j = 0;j+1<facts[i].size();j++){
                d.merge(facts[i][j],facts[i][j+1]);
            }
        }
        vector<int> snums = nums;
        sort(snums.begin(),snums.end());
        
        for(int i = 0;i < n;i++){
            int p = d.get(nums[i]);
            // cout << i << " " << nums[i] << " "<< " "<< p << endl;
            G[p].push_back(i);
        }
        
        for(int i = 0;i < N;i++){
            if(!G[i].size()) continue;
            vector<int> curr;
            vector<int> old;
            for(int idx : G[i]) old.push_back(nums[idx]);
            for(int idx : G[i]) curr.push_back(snums[idx]);
            sort(old.begin(),old.end());
            sort(curr.begin(),curr.end());
//             for(int j = 0;j < old.size();j++){
//                 cout << old[j] << " ";
//             }
//             cout  << endl;
            
//             for(int j = 0;j < curr.size();j++){
//                 cout << curr[j] << " ";
//             }
            // cout  << endl;
            if(old!=curr)ans= false;
        }
        return ans;
    }
};