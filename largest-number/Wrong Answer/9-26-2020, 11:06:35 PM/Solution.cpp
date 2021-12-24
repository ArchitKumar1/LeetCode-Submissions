// https://leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            string x = to_string(a);
             string y = to_string(b);
            if(x.size()>y.size()){
                swap(x,y);
            }
            
            for(int i = 0;i<x.size();i++){
                if(x[i] < y[i])return 0;
                else if(x[i] > y[i]) return 1;
            }
            return 1;
            
        });
        string ans;
        for(int c : nums)ans += to_string(c);
        while(ans.front() == '0' && ans.size()){
            ans.erase(*ans.begin());
        }
        return ans;
    }
};