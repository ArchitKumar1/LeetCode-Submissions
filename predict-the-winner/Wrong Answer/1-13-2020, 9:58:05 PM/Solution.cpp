// https://leetcode.com/problems/predict-the-winner

class Solution {
public:
    
    int solve(vector<int>&nums,int n,int s,int e,int pos){
        
        if(s == e)return (pos == 0 ? nums[s] : 0);
        if(pos == 0) return max(nums[s]+solve(nums,n,s+1,e,pos^1),nums[e]+solve(nums,n,s,e-1,pos^1));
        else return max(solve(nums,n,s+1,e,pos^1),solve(nums,n,s,e-1,pos^1));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        cout << solve(nums,n,0,n-1,0) << endl;
        long long int sum =0 ;
        for(int &x: nums){
            sum += x;
        }
        int p1 = solve(nums,n,0,n-1,0);
        return (p1>=sum-p1? 1 : 0);
        
    }
};