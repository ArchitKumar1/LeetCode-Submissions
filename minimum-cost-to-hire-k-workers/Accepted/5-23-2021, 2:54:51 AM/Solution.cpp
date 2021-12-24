// https://leetcode.com/problems/minimum-cost-to-hire-k-workers

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int N = quality.size();
        
        priority_queue<int> pq;
        vector<pair<double,double>> v;
        for(int i= 0; i < N;i++){
            v.emplace_back(1.0*wage[i]/quality[i],quality[i]);
        }
        sort(v.begin(),v.end());
        
        double ans = DBL_MAX;
        double sum = 0;
        
        for(int i = 0;i < N;i++){
            auto [ratio , q] = v[i];
            pq.push(q);
            sum += q;
            if(pq.size() > k){
                auto p = pq.top(); pq.pop();
                sum -= p;
            }
            if(pq.size() == k){
                ans = min(ans,1.0*sum * ratio);
            }
        }
        return ans;
        
    }
};