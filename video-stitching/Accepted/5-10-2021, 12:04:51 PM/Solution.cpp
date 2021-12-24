// https://leetcode.com/problems/video-stitching

class Solution {
public:
    int videoStitching(vector<vector<int>>& v, int T) {
        int N = v.size();

        sort(v.begin(),v.end());
        
        int ans = 0;
                
        int mx = 0;
        int i = 0;
        while(mx < T){
            int best = mx;
            while(i < N  && v[i][0] <= mx){
                best = max(best,v[i][1]);
                i++;
            }
            if(best == mx) return -1;
            mx = best;
            ans++;
        }
        return ans;

    }
};