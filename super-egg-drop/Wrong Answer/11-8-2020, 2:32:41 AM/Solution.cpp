// https://leetcode.com/problems/super-egg-drop

class Solution {
public:
    int superEggDrop(int K, int N) {
        return (int)ceil(log2(N+1));
    }
};