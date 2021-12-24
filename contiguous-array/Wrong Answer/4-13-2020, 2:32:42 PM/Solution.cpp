// https://leetcode.com/problems/contiguous-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> cnt(200000,-1);
        cnt[100000] = 0;
        
        int ans =0;
        int curr = 100000;
        for(int i = 0;i<nums.size();i++){
            curr += (nums[i] == 1 ? 1 : -1);
            cout << i << " " << nums[i] << " " << cnt[curr]+1 << endl;
            if(cnt[curr] != -1){
                ans = max(ans,i +1 + cnt[curr]);
            }else{
                cnt[curr] = i+1;
            }
        }
        return ans;
        
    }
};