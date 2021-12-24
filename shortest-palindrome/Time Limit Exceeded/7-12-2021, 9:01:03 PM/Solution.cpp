// https://leetcode.com/problems/shortest-palindrome

class Solution {
public:
    
    string shortestPalindrome(string s) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
        string ans;
        string rev = s;
        reverse(rev.begin(),rev.end());
        for (int i = 0; i < s.size(); ++i) {
		if (rev.substr(i) == s.substr(0, s.size() - i)) {
			return rev.substr(0, i) + s;
            }
        }
        return rev + s;
    }
};