// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> v;
        int N = ranges.size();
        
        for(int i = 0;i < N;i++){
            v.emplace_back(i - ranges[i], i + ranges[i]);
        }
        sort(v.begin(),v.end());
        
        int ans = 0;
                
        int mx = 0;
        int i = 0;
        while(mx < n){
            int best = mx;
            while(i < N  && v[i].first <= mx){
                best = max(best,v[i].second);
                i++;
            }
            if(best == mx) return -1;
            mx = best;
            ans++;
        }
        return ans;
    }
};