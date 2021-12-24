// https://leetcode.com/problems/max-value-of-equation

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& p, int k, int res = INT_MIN) {
        deque<int> d;
        for (int j = 0; j < p.size(); ++j) {
            while (!d.empty() && p[j][0] - p[d.front()][0] > k)
                d.pop_front();
            if (!d.empty())
                res = max(res, p[d.front()][1] - p[d.front()][0] + p[j][1] + p[j][0]);
            while (!d.empty() && p[d.back()][1] - p[d.back()][0] < p[j][1] - p[j][0])
                d.pop_back();
            d.push_back(j);
        }
        return res;
    }
};