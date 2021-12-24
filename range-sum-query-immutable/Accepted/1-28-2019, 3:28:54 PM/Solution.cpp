// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
public:
    int n;
    int t[2000010];
    NumArray(vector<int> nums) {
        n=nums.size();
        for(int i=0;i<nums.size();i++)
            t[i+n]=nums[i];
        for (int i = n - 1; i > 0; --i) 
            t[i] = t[i<<1] + t[i<<1|1];
    }
    
    int sumRange(int l, int r) {
        int res = 0;
        r++;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
      }
      return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */