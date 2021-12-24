// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:
    
    int BIT[100000] = {0};
    vector<int> N;
    NumArray(vector<int>& nums) {
        N = nums;
        for(int i = 0;i<nums.size();i++) add(i,nums[i]);
    }
    void add(int i, int val) {
        i++;
        while(i<=100000){
            BIT[i] += val;
            i+=(i&-i);
        }
    }
    void update(int i, int val) {
        add(i,-N[i]);
        N[i]= val;
        add(i,val);
    }
    int sum(int i){
        int res =0 ;
        if(i ==0) return 0;
        while(i>0){
            res += BIT[i];
            i-=(i&-i);
        }
        return res;
    }
    int sumRange(int i, int j) {
        
        return sum(j+1) - sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */