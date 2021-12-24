// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int s = 0;
        int mini = 0;
        for(int c :nums){
            s += c;
            mini = min(mini,s);
        }
        if(mini < 0){
            return abs(mini) + 1;
        }else{
            return 1;
        }
    }
};