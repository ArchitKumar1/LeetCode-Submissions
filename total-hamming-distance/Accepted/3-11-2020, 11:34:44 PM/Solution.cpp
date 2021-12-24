// https://leetcode.com/problems/total-hamming-distance

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        int n = nums.size();
        vector<int> bit(32,0);
        for(int j = 0;j<n;j++){
            for(int i = 0;i<32;i++){
                if((1<<i)&nums[j]){
                    bit[i] +=1;
                }
            }
        }
        int total = 0;
        for(int i = 0;i<32;i++){
            total += bit[i] * (n-bit[i]);
        }
        return total;
        
    }
};