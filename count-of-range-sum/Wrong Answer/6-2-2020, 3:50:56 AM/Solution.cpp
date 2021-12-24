// https://leetcode.com/problems/count-of-range-sum

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long int curr = 0;
        long long int ans = 0;
        
        map<long long int,int> m1;
        
        m1[0] = 1;
        for(int x : nums){
            curr += x ;
            m1[curr]++;
            int cnt = m1[curr-x] ;
            if(cnt >= lower && cnt <=upper) ans+= cnt;
        }
        return ans;
    }
};