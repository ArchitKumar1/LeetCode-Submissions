// https://leetcode.com/problems/sum-of-beauty-of-all-substrings

class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            map<char,int> m1;
            for(int j = i;j<n;j++){
                m1[s[j]]++;
                int mi = INT_MAX;
                int ma = INT_MIN;
                for(auto it : m1){
                    mi = min(mi,it.second);
                    ma = max(ma,it.second);
                }
                ans+= ma-mi;
            }
        }
        return ans;
    }
};