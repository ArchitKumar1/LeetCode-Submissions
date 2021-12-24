// https://leetcode.com/problems/predict-the-winner

class Solution {
public:
    
    int solve(vector<int>&nums,int n,int s,int e,int pos){
        
        if(s == e)return (pos == 0 ? nums[s] : 0);
        int a = solve(nums,n,s+1,e,pos^1);
        int b = solve(nums,n,s+1,e,pos^1);
        if(pos == 0) return max(nums[s]+a,nums[e]+b);
        else return min(a,b);
    }
    bool PredictTheWinner(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();
        long long int sum =0 ;
        for(int &x: nums){
            sum += x;
        }
        int p1 = solve(nums,n,0,n-1,0);
        return (p1>=sum-p1? 1 : 0);
        
    }
};