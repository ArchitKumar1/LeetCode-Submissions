// https://leetcode.com/problems/find-the-winner-of-the-circular-game

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> nums(n);
        iota(nums.begin(),nums.end(),1);
        
        int i = 0;
        while(nums.size() > 1){
            int x = k-1;
            while(x--){
                i = (i+1)%nums.size();
            }
            nums.erase(nums.begin()+i);
        }
        return nums[0];
        
    }
    
};