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
                i++;
                best = max(best,v[i].second);
            }
            if(best == mx) return -1;
            mx = best;
            ans++;
        }
        return ans;
    }
//     int videoStitching(vector<vector<int>>& clips, int T, int res = 0) {
//   sort(begin(clips), end(clips));
//   for (auto i = 0, st = 0, end = 0; st < T; st = end, ++res) {
//     while (i < clips.size() && clips[i][0] <= st) end = max(end, clips[i++][1]);
//     if (st == end) return -1;
//   }
//   return res;
// }
};