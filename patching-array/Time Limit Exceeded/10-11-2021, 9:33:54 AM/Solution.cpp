// https://leetcode.com/problems/patching-array

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int N = nums.size();
        
        int answer = 0;
        int64_t sum = 0;
        
        int miss = 0;
        int i = 0;
        while(miss  <= n){
            if( i < N && nums[i] <= miss){
                miss += nums[i++];
            }else{
                answer++;
                miss += miss;
            }
        }
        return answer;
//         for(int i = 0;i < N;i++){
//             while(sum <= n && ){
//                 sum += sum + 1;
//                 answer += 1;
//             }
//             sum += nums[i];
            
//         }
//         return answer;
    }
};