// https://leetcode.com/problems/maximum-score-of-a-good-subarray

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int fans = 0;
        int ans = 0;
        int n = nums.size();
        
        int i = k;
        int j = k;
        
        int mini = INT_MAX;
        
        while(i>= 0 || j < n){
            int ch = 0;
            if(i == j){
                mini = min(mini,nums[i]);
                ans = max(ans,mini*(j-i+1));
                i--,j++;
                ch = 1;
            }else{
                if(i == -1){
                    mini = min(mini,nums[j]);
                    int newans = mini*(j-i);
                    ans = max(ans,newans);
                    j++; ch = 1;
                    
                }else if(j == n){
                    mini = min(mini,nums[i]);
                    int newans = mini*(j-i);
                    ans = max(ans,newans);
                    i--; ch = 1;
                }else{
                    int l = nums[i];
                    int r = nums[j];
                    if(l > r){
                        // int newans = min(mini,nums[i])*(j-i);
                        // if(newans >= ans){
                        //     ans = newans;
                        //     mini = min(mini,nums[i]);
                        //     i--; ch = 1;
                        // }
                        mini = min(mini,nums[i]);
                        int newans = mini*(j-i);
                        ans = max(ans,newans);
                        i--; ch = 1;
                    }else{
                        // int newans = min(mini,nums[j])*(j-i);
                        // if(newans >= ans){
                        //     ans = newans;
                        //     mini = min(mini,nums[j]);
                        //     j++; ch = 1;
                        // }
                        mini = min(mini,nums[j]);
                        int newans = mini*(j-i);
                        ans = max(ans,newans);
                        j++; ch = 1;
                    }
                }
            }
            if(!ch) break;
        }
        return ans;
    }
};