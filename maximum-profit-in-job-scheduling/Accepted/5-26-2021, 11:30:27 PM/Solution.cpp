// https://leetcode.com/problems/maximum-profit-in-job-scheduling

const int N = 6e4;
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        set<pair<int,int>> st;
        vector<int> val(N);
        st.emplace(0,0);
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
            auto lb = st.upper_bound({s,INT_MAX});
            auto pr = *(--lb);
            
            auto lb2 = st.lower_bound({e,INT_MAX});
            auto pr2 = *(--lb2);
            
            pair<int,int> npr;
            npr.second = max(pr.second + p ,pr2.second);
            npr.first = e;
            st.insert(npr);
            ans = max(ans,npr.second);
        }
        return ans;
    }
};