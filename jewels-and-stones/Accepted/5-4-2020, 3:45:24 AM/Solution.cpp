// https://leetcode.com/problems/jewels-and-stones

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,int> m1;
        for(char c : J) m1[c]++;
        int ans = 0;
        for(char c : S){
            if(m1[c] == 1){
                ans++;
            }
        }
        return ans;
    }
};