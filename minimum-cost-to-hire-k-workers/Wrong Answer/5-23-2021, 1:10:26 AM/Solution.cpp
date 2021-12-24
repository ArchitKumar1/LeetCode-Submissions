// https://leetcode.com/problems/minimum-cost-to-hire-k-workers

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int N = quality.size();
        
        priority_queue<tuple<double,int,int>> pq;
        vector<tuple<int,double,int>> v;
        for(int i= 0; i < N;i++){
            v.emplace_back(wage[i],1.0*quality[i]/wage[i],quality[i]);
        }
        sort(v.begin(),v.end());
        
        double ans = numeric_limits<double>::max();
        int sum = 0;
        multiset<double> ms;
        
        for(int i = 0;i < N;i++){
            int q,w; double ratio;
            tie(w,ratio,q) = v[i];
            pq.emplace(ratio,q,w);
            ms.insert(ratio);
            
            sum += q;
            if(pq.size() > k){
                int q,w; double ratio;
                tie(ratio,q,w) = pq.top();
                pq.pop();
                ms.erase(ms.find(ratio));
                sum -= q;
            }
            if(pq.size() == k){
                ans = min(ans,sum/ *ms.begin());
            }
        }
        return ans;
        
    }
};