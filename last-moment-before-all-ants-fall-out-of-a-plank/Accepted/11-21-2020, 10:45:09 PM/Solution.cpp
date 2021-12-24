// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for(int c : left){
            ans = max(ans,c);
        }
        for(int c : right){
            ans = max(ans,n-c);
        }
        return ans;
        
    }
};