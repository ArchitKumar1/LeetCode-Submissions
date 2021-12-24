// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> p(n+2,0),s(n+2,0);
        
        for(int i = 1;i<=n;i++){
            p[i] = 1;
            for(int j = 1;j<i;j++){
                if(nums[i-1] > nums[j-1]){
                    p[i] = max(p[i],1+p[j]);
                }
            }
        }
        
        
        for(int i = n;i>=1;i--){
            s[i] = 1;
            for(int j = n;j>i;j--){
                if(nums[i-1] > nums[j-1]){
                    s[i] = max(s[i],1+s[j]);
                }
            }
        }
        for(int i = 1;i<=n;i++){
            cout << s[i] << " ";
        }
        cout << endl;
        for(int i = 1;i<=n;i++){
            cout << p[i] << " ";
        }
        cout << endl;
        int ans = 0;
        for(int i = 2;i<n;i++){
            if(p[i]>=2 && s[i]>=2){
                ans = max(ans,p[i]-1+s[i]);
            }
        }
        return n - ans;
    }
};