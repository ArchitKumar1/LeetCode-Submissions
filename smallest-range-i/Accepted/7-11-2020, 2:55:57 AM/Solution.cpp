// https://leetcode.com/problems/smallest-range-i

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxi = *max_element(A.begin(),A.end());
        int mini = *min_element(A.begin(),A.end());
        
        return max(0,maxi - mini -2*K);
        
        
    }
};