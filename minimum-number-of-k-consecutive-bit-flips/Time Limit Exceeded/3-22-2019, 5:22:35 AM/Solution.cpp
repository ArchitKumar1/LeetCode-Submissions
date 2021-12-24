// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips

class Solution {
public:
    int minKBitFlips(vector<int>& a, int k) {
        int flips = 0;
        auto flip = [](vector<int>& a, int s, int k){for(int i=s; i<s+k; i++) a[i] = 1 - a[i]; };
        for(int i=0; i<a.size(); i++){
            if(!a[i]){
                if(i > a.size()-k) return -1;
                flip(a,i,k);
                flips++;
            }
        }
        return flips;
    }
};