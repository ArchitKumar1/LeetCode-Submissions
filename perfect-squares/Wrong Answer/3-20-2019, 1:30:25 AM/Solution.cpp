// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        for(int i=1;i<=ceil(floor(sqrt(n)));i++){
            sq.push_back(i*i);
        }
        int ans = 0;
        for(int i=sq.size()-1;i>=0;i--){
            int x = n/sq[i];
            ans+=x;
            n= n - x*sq[i];
        }
        return ans;
    }
};