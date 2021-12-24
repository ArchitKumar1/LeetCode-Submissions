// https://leetcode.com/problems/largest-number

class Solution
{
public:
    string largestNumber(vector<int> & nums)
    {
        vector<string> vec;
        std::transform(nums.begin(), nums.end(), std::back_inserter(vec), [](int n){ return std::to_string(n);});
        std::sort(vec.rbegin(), vec.rend(), [](const string & s, const string & t) { return s + t < t + s; });
        string res = std::accumulate(vec.begin(), vec.end(), string());
        return res.front() == '0' ? "0" : res;
    }
};