// https://leetcode.com/problems/maximum-profit-in-job-scheduling

const int N = 6e4;
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> pt(N);
        
        vector<tuple<int,int,int>> v;
        int N  = startTime.size();
        for(int i =0;i <N;i++){
            v.emplace_back(endTime[i],startTime[i],profit[i]);
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(auto x : v){
            int e,s,p;
            tie(e,s,p) = x;
            pt[e] = max(pt[e] ,pt[s] + p);
            ans = max(ans,pt[e]);
        }
        return ans;
    }
};