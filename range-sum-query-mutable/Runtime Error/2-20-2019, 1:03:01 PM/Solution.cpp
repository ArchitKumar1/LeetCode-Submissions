// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:
   
    int t[202] = {0};
    int n;
    NumArray(vector<int> nums) {

        n = nums.size();
        memset(t,0,sizeof(t));
        for (int i = 0; i < n; ++i)
		    t[n+i] = nums[i];
        for (int i = n - 1; i > 0; --i)
	        t[i] = t[2*i] + t[2*i+1];
    }
    void update(int p, int value) {
        
        for (t[p += n] = value; p > 1; p >>= 1) 
            t[p>>1] = t[p] + t[p^1];
    }
    
    int sumRange(int l, int r) {
        r++;
        int res = 0;
          l=l+n,r=r+n;
          for (l,r; l < r; l=l/2, r=r/2) {
            if (l&1)
                res += t[l++];
            if (r&1)
                res += t[--r];
          }
          return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */