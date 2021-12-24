// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s1;
        int len = nums.size();
        int a = 0;
        int c = 1 << len + 1;
        vector<int> temp;
        while(a!= c){
            for(int i = 0;i<nums.size();i++){
                if(a & nums[i])
                    temp.push_back(nums[i]);
            }
            s1.insert(temp);
            temp.clear();
            a++;
        }
        vector<vector<int>> ans;
        for(auto c : s1)
            ans.push_back(c);
        return ans;
    }
};