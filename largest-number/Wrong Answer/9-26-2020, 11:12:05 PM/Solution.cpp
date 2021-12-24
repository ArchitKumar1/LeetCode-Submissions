// https://leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            string x = to_string(a);
             string y = to_string(b);
            string xx = x+y;
            string yy = y+x;
            return xx < yy;
        });
        string ans;
        for(int c : nums)ans += to_string(c);
        while(ans.front() == '0' && ans.size()){
            ans.erase(*ans.begin());
        }
        return ans;
    }
};