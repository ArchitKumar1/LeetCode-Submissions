// https://leetcode.com/problems/patching-array

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        nums.push_back(n);
        int N = nums.size();
        sort(nums.begin(),nums.end());
        
        int answer = 0;
        int64_t sum = 1;
        for(int i = 0;i < N;i++){
            while(sum < nums[i]){
                sum += sum;
                answer += 1;
            }
            sum += nums[i];
            
        }
        return answer;
    }
};