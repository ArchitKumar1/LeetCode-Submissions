// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<int> cnt(100002,0);
        for(int c : nums){
            cnt[c+50001]++;
        }
        vector<int> ans;
        for(int i = 0;i<100002;i++){
            if(cnt[i] > 0){
                for(int x = 0;x<cnt[i];x++){
                    ans.push_back(i-50001);
                }
            }
        }
        return ans;
    }
};