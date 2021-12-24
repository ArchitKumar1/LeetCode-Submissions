// https://leetcode.com/problems/create-sorted-array-through-instructions



class Solution {
    
private:
    const static int N = 1e6;
    vector<int> BIT(1000000);
public:
    
    
    void add(int i){
        for(i<N;i+=(i&-i)) BIT[i]+= 1;
    }
    int get(int i){
        int ans = 0;
        for(i>0;i-=(i&-i)) ans+= BIT[i];
        return ans;
    }
    int createSortedArray(vector<int>& instructions) {
        long long int ans = 0;
        int cnt = 0;
        for(int c: instructions){
            int l = get(c-1);
            int r = cnt - get(c);
            add(c);
            ans += min(l,r);
        }
        ans %= MOD;
        return (int)ans;
    }
};