// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int a = 0;
        int mi = *min_element(nums.begin(),nums.end());
        int ma = *max_element(nums.begin(),nums.end());
        for(int i=mi;i<=ma;i++){
            a=a^i;
        }
        for(int i=0;i<nums.size();i++){
            a=a^nums[i];
        }
        if(a == 0){
            return max(0,max(max(mi,mi+1),max(ma,ma+1)));
        }
        return a;
    }
};