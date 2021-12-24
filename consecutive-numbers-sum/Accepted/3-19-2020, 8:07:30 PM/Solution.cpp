// https://leetcode.com/problems/consecutive-numbers-sum

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int M = 5e4;
        vector<long long int> all(M,1);
        for(int i =2;i<M;i++){
            all[i] = all[i-1] + i;
        }
        int ans = 0;
        for(int i =1;i<M;i++){
            if((N-all[i] >= 0 ) && (N-all[i])%i == 0){
                ans +=1;
            }
        }
        return ans;
    }
};