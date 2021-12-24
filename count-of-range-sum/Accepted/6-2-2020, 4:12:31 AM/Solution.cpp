// https://leetcode.com/problems/count-of-range-sum

class Solution {
public:
    
     int countRangeSum(vector<int>& nums, int lower, int upper) {
        map<long, int> m;
        int count = 0;
        long sum = 0;
        
        if (nums.empty())
            return 0;
        
        m[0] = 1;
        for (auto num: nums) {
            sum += num;
            auto l = m.lower_bound(sum - (long)upper);
            auto h = m.upper_bound(sum - (long)lower);
            for (auto it = l; it != h; it++) {
                count += it->second;
            }
            m[sum]++;
        }
        
        return count;
    }
        
      
};