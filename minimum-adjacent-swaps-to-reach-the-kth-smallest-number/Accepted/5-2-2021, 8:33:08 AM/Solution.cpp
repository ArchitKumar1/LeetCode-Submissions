// https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number

class Solution {
public:
    int getMinSwaps(string t, int k) {
        string num = t;
        while(k--){
            next_permutation(num.begin(),num.end());
        }
        int i = 0, j = 0;
        int ans = 0;
        while (i < t.size()) {
            j = i;
            while (t[j] != num[i]) {
                j += 1;
            }
            while (i < j) {
                swap(t[j],t[j-1]);
                j -= 1;
                ans += 1;
            }
            i += 1;
        }
        return ans;
        
    }
};