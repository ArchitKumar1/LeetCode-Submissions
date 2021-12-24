// https://leetcode.com/problems/eliminate-maximum-number-of-monsters

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> times;
        times.reserve(n);
        for(int i = 0; i < n;i++){
            times.push_back(dist[i]/speed[i] + ((dist[i]%speed[i]) > 0));
        }
        sort(times.begin(),times.end());
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(times[i] > i) ans++;
            else break;
        }
        return ans;
    }
};