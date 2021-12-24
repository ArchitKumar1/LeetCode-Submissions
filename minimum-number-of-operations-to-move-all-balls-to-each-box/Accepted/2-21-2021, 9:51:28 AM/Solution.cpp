// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                ans[i] += (boxes[j]=='1')*(abs(j-i));
            }
        }
        return ans;
    }
};