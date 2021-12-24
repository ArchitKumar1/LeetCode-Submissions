// https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        set<int> st;
        unordered_map<int,int> val;
        st.emplace(0);
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
            auto pr = *(--st.upper_bound(s));
            auto pr2 = *(--st.upper_bound(e));
            
            val[e] = max(val[pr] + p ,val[pr2]);
            st.insert(e);
            ans = max(ans,val[e]);
        }
        return ans;
    }
};