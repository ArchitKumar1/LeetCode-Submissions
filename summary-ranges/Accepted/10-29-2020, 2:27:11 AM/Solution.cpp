// https://leetcode.com/problems/summary-ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int cnt = 1;
            int o = i;
            while(i+1<n && nums[i+1] == nums[i] + 1){
                cnt += 1;
                i++;
            }
            if(cnt > 1){
                ans.push_back(to_string(nums[o]) + "->" + to_string(nums[i]));
            }else{
                 ans.push_back(to_string(nums[i]));
            }
        }
        return ans;
                    
    }
};