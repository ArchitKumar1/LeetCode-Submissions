// https://leetcode.com/problems/closest-subsequence-sum

class Solution {
public:
    
    
    
    void solve(vector<int> &x,vector<int> &nums, int i,int ans){
        if(i == nums.size()){
            x.push_back(ans);
            return;
        }
        solve(x,nums,i+1,ans+nums[i]);
        solve(x,nums,i+1,ans);
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        
        int n = nums.size();
        
        
        vector<int> x,y,nums1,nums2;
        
        for(int i = 0;i<n;i++){
            if(i&1)nums1.push_back(nums[i]);
            nums2.push_back(nums[i]);
        }
        solve(x,nums1,0,0);
        solve(y,nums2,0,0);
        
        sort(x.begin(),x.end());
        x.resize(unique(x.begin(),x.end()) - x.begin());
        
        
        int GAP = INT_MAX;
        
        auto upd = [&](int x){
            int gap = abs(goal -x);
            GAP = min(GAP,gap);
        };
        
        for(int c : y ){
            auto ub = upper_bound(x.begin(),x.end(),goal-c);
            auto lb = lower_bound(x.begin(),x.end(),goal-c);
            
            if(ub!=x.end()) upd(*ub+c);
            if(lb!=x.end()) upd(*lb+c);
            
            if(ub!=x.end()) ub = next(ub);
            if(lb!=x.begin()) lb = prev(ub);
            
            if(ub!=x.end()) upd(*ub+c);
            if(lb!=x.end()) upd(*lb+c);
            
        }
        return GAP;
        
    }
};