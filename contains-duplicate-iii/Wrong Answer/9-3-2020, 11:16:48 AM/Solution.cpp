// https://leetcode.com/problems/contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> s;
        int cnt = 0;
        int mingap = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            if(s.size() == 0){
                s.insert(nums[i]);
                cnt++;
            }else{
                auto t = s.lower_bound(nums[i]);
                auto u = s.upper_bound(nums[i]);
                mingap = min(mingap,nums[i]-*t);
                
                if(u != s.end()){
                     mingap = min(mingap,*u-nums[i]);
                }
                s.insert(nums[i]);
                cnt++;
                if(cnt == k){
                    s.erase(nums[i-k+1]);
                    cnt--;
                }
            }
        }
        return mingap<=k;
    }
};