// https://leetcode.com/problems/minimum-space-wasted-from-packaging

class Solution {
public:
    int minWastedSpace(vector<int>& p, vector<vector<int>>& b) {
        const int M = 1e9 + 7;
        sort(p.begin(),p.end());
        int n = p.size();
        vector<long long> sums = {0};
        for(int c : p){
            sums.push_back(sums.back()+c);
        }
        long long tsum = 0;
        for(int c : p) tsum+=c;
        long long ans = 1e18;
        long long fans = -1;
        for(auto x : b){
            sort(x.begin(),x.end());
            long long back = 0;
            long long wastage = 0;
            vector<long long> idxs;
            for(auto y : x){
                auto it = upper_bound(p.begin(),p.end(),y);
                long long index = it - p.begin();
                index--;
                idxs.push_back(index);
            }
            for(int i = 0;i < idxs.size();i++){
                wastage += 1LL * x[i] * (idxs[i] - back+1);
                back = idxs[i]+1;
            }
            wastage -= tsum;
            if(back == n){
                ans = min(ans,wastage);
            }
        }
        return ans == 1e18 ? -1 : ans%M;
    }
};