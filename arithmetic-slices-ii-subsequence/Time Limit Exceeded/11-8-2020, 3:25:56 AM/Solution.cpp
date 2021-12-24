// https://leetcode.com/problems/arithmetic-slices-ii-subsequence

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        map<long long ,int> m1[1234];
        
        int n = A.size();
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                long long diff = (long long)A[i] - (long long)A[j];
                m1[i][diff] += m1[j][diff];
                ans += m1[j][diff];
            
                m1[i][diff] += 1;
            }
            
        }

        return ans;
    }
};