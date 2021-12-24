// https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses

class Solution {
public:
    int minimumBuckets(string s) {
        int ans = 0;
        int n = s.size();
        bool safe = 1;
        for(int i = 0;i+2<n;i++){
            if(s.substr(i,3) == "HHH") safe = false;
        }
        for(int i=0;i<n;i++){
            if(s[i] == 'H'){
                safe&= ((i>0?(s[i-1] =='.'):0) || (i!=(n-1)?(s[i+1] =='.'):0));
            }
        }
        int cnt = count(s.begin(),s.end(),'H');
        for(int i=0;i+2<n;i++){
            if(s.substr(i,3) == "H.H"){
                ans += 1;
                cnt -= 2;
                i += 2;
            }
        }
        ans += cnt;
        if(!safe) return -1;
        return ans;
    }
};