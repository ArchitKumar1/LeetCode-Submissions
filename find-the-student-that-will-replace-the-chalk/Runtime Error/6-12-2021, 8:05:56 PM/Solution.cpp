// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = 0;
        for(int c : chalk) sum += c;
        int q = k / sum;
        int r = k % sum;
        int ans = 0;
        if(r == 0) ans = 0;
        else{
            k = k - q*sum;
            int pos = 0;
            for(int c : chalk){
                k-=c;
                if(k < 0){
                    ans = pos;
                    break;
                }
                pos++;
            }
        }
        return ans;
    }
};