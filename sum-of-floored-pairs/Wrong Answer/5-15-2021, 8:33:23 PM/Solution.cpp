// https://leetcode.com/problems/sum-of-floored-pairs

class fenwick{
    public:
    int n;
    vector<int> BIT;
    fenwick(int _n){
        n = _n;
        BIT.assign(n,0);
    }
    void add(int v,int i){
        for(;i < n;i+=(i&-i)){
            BIT[i] += v;
        }
    }
    int get(int i){
        int ans = 0;
        for(;i > 0;i-=(i&-i)){
            ans += BIT[i];
        }
        return ans;
    }
    int sum(int l,int r){
        return get(r) -get(l-1);
    }
    int value_at(int i){
       return sum(i,i);
    }
};
const int N = 1.5e5+100;
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int n = nums.size();
        fenwick tree(N);
        for(int c : nums){
            tree.add(1,c);
        }
        int ans = 0;
        int MOD = 1e9+7;
        map<int,int> m1;
        for(int c : nums){
            if(m1[c] != 0){
                ans += m1[c];
                continue;
            }
            int fans = 0;
            for(int d = 2*c; d < N;d += c){
                fans += 1LL*((d/c) - 1)*tree.sum(d-c,d-1) % MOD;
                fans %= MOD;
            }
            m1[c] = fans;
            ans += fans;
            ans %= MOD;
        }
        return ans;
    }
};