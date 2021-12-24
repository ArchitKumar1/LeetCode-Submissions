// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        long long a = 0;
        long long mi = *min_element(nums.begin(),nums.end());
        long long ma = *max_element(nums.begin(),nums.end());
        for(long long i=mi;i<=ma;i++){
            a=a^i;
        }
        for(long long i=0;i<nums.size();i++){
            a=a^nums[i];
        }
        if(a == 0){
            return (int)max(0LL,max(max(mi,mi+1),max(ma,ma+1)));
        }
        return (int)a;
    }
};