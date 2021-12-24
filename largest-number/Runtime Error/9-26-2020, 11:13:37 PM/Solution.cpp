// https://leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return to_string(nums[0]);
        sort(nums.begin(),nums.end(),[&](int a,int b){
            string x = to_string(a);
             string y = to_string(b);
            string xx = x+y;
            string yy = y+x;
            return xx > yy;
        });
        string ans;
        for(int c : nums)ans += to_string(c);
        while(ans.front() == '0' && ans.size() > 1){
            ans.erase(*ans.begin());
        }
        return ans;
    }
};