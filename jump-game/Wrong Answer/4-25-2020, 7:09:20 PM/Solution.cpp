// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = 0;
        bool ok = 1;
        for(int c : nums){
            if(curr < 0) ok = 0;
            curr = max(curr-1,c);
        }
        return ok;
    }
};