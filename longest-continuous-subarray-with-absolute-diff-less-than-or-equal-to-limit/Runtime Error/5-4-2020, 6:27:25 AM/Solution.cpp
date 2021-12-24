// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        int n = nums.size();
        stack<int> mini,maxi;
        
        
        auto stacky = [&](int x){
            if(mini.size() == 0){
                mini.push(x);
            }else{
                if(mini.top() >= x){
                    mini.push(x);
                }
            }
            if(maxi.size() == 0){
                maxi.push(x);
            }else{
                if(maxi.top() <= x){
                    maxi.push(x);
                }
            }
        };
        auto remove = [&](int x){
            
            if(mini.top() == x){
                mini.pop();
            }
            if(maxi.top() == x){
                maxi.pop();
            }
            
        };
        auto check = [&](){
            int a = maxi.size() ? maxi.top() : 0;
            int b = mini.size() ? mini.top() : 0;
            return a -b;
        };
        
        int i = 0;
        for(int j =0;j<n;j++){
            stacky(nums[j]);
            
            while(check() > limit){
                // cout <<  " " << j << " "  << i << endl;
                remove(nums[i]);
                i++;
            }
            ans =max(ans,j-i+1);
        }
        return ans;
    }
};