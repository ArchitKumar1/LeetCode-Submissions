// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> q;
        for(auto c: matrix){
            for(auto d: c){
                q.push_back(d);
            }
        }
        sort(q.begin(),q.end());
        return q[k - 1];
    }
};