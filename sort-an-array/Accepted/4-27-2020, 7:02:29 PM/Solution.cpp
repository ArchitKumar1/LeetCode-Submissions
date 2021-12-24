// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> cnt(110000,0);
        for(int c : nums){
            cnt[c+55000]++;
        }
        vector<int> ans;
        for(int i = 0;i<110000;i++){
            if(cnt[i] > 0){
                for(int x = 0;x<cnt[i];x++){
                    ans.push_back(i-55000);
                }
            }
        }
        return ans;
    }
};