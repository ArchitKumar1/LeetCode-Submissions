// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int>res;
        for(int i = 0; i < nums.size();i++){
            ms.insert(nums[i]);
            if((i-k)>=0){
                ms.erase(ms.find(nums[i-k]));
                
            }
            if(i-k>=-1)res.push_back(*ms.rbegin());
        }
        return res;
    }
};