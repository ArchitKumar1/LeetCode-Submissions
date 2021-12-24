// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int num) {
        int cnt = 0;
        int index = -1;
        for(int i = 0;i<32;i++){
            if((1<<i)&num ) cnt += 1,index=i;
        }
        cout << index << " "<< cnt << endl;
        return (index && index%2^1 && cnt==1);
    }
};