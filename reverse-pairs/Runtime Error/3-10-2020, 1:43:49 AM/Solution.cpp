// https://leetcode.com/problems/reverse-pairs

class Solution {
public:
    vector<long long int>BIT;
    int N;
    void add(int num,int pos){
        while(pos <= N){
            BIT[pos] += num;
            pos += (pos&-pos);
        }
    }
    long long int get(int pos){
        long long int res =0 ;
        while(pos > 0){
            res += BIT[pos];
            pos -= (pos&-pos);
        }
        return res;
    }
    int reversePairs(vector<int>& nums) {
        N = 1e5;
        BIT.assign(N+1,0);
        int n = nums.size();
        int res = 0;
        for(int i = 0;i<n;i++){
            add(1,nums[i]);
            res += get(N) - get(2*nums[i]); 
        }
        // cout << get(N) << endl;
        return res;
    }
};