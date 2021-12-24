// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int c : chalk) sum += c;
        long long q = k / sum;
        long long r = k % sum;
        long long ans = 0;
        if(r == 0) ans = 0;
        else{
            k = k - q*sum;
            long long pos = 0;
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