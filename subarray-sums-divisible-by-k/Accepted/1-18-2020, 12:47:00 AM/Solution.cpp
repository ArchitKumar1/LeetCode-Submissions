// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n = A.size();
        unordered_map<long long int,int> m1;
        int min_ele = *min_element(A.begin(),A.end());
        m1[0] =1;
        long long int  sum =0 ;
        long long int  fsum =0 ;
        for(int i =0;i<n;i++){
            sum +=A[i];
            long long int tsum = (K + sum%K)%K;
            fsum += m1[tsum]++;
        }
        return fsum;
    }
};