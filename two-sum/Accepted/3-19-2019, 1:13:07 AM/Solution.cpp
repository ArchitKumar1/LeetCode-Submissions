// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m1,m2;
        for(int i=0;i<nums.size();i++){
            m1[nums[i]] = i + 1;
        }
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            if(m1[target-nums[i]] && m1[target-nums[i]] != i+1){
                temp.push_back(i);
                temp.push_back(m1[target-nums[i]]-1);
                break;
            }
        }
        return temp;
    }
};