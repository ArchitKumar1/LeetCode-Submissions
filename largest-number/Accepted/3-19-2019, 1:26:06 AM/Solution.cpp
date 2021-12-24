// https://leetcode.com/problems/largest-number

class Solution
{
public:
    string largestNumber(vector<int> & nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<string> vec;
        transform(nums.begin(), nums.end(), back_inserter(vec), [](int n){ return to_string(n);});
        sort(vec.rbegin(), vec.rend(), [](const string & s, const string & t) { return s + t < t + s; });
        string res = accumulate(vec.begin(), vec.end(), string());
        return res.front() == '0' ? "0" : res;
    }
};