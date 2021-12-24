// https://leetcode.com/problems/contiguous-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> cnt(200000,-2);
        cnt[100000] = -1;
        int ans = 0;
        int curr = 100000;
        for(int i = 0;i<nums.size();i++){
            curr += (nums[i] == 1 ? 1 : -1);
            cout << i << " " << nums[i] << " " << cnt[curr] << endl;
            if(cnt[curr] != -2){
                ans = max(ans,i - cnt[curr]);
            }else{
                cnt[curr] = i;
            }
        }
        return ans;
        
    }
};