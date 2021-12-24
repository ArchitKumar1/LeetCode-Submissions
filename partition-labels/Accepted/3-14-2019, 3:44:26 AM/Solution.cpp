// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int start = 0, end = 0, n = S.size();
        unordered_map<char, int> m;
        for (int i= 0; i < n; ++i) m[S[i]] = i;
        for (int i= 0; i < n; ++i) {
            end = max(end, m[S[i]]);
            if (end == i) {
                res.push_back(end-start+1);
                start = i+1;
            }
        }
        return res;
    }
};