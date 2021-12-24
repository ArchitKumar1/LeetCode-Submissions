// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        ios_base::sync_with_stdio();
        cin.tie(NULL);
        cout.tie(NULL);
        int cur = 0, res = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i >= K) cur -= A[i - K] / 2;
            if (cur & 1 ^ A[i] == 0) {
                if (i + K > A.size()) return -1;
                A[i] += 2;
                cur++;
                res++;
            }
        }
        return res;
    }
};