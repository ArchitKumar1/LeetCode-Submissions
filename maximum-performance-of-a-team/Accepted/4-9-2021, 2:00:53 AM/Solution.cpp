// https://leetcode.com/problems/maximum-performance-of-a-team

class Solution {
public:
    const int M = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
//         priority_queue<int,vector<int>,greater<int>> pq;
        
//         vector<pair<int,int>> v;
//         for(int i=0;i<n;i++){
//             v.emplace_back(efficiency[i],speed[i]);
//         }
//         sort(v.rbegin(),v.rend());
//         int sum  = 0; 
//         long long ans = 0;

//         for(int i = 0;i<n;i++){
//             pq.push(v[i].second);
//             sum += v[i].second;
//             if(pq.size() > k)
//                 sum -= pq.top(),pq.pop();
//             ans = max(ans,(long long)v[i].first*sum);
//         }
        // return ans % M;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.emplace_back(efficiency[i],speed[i]);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int mini = INT_MAX;
        long long sum  = 0; 
        long long ans = 0;
        for(int i = 0;i<k;i++){
            mini = v[i].first;
            sum += v[i].second;
            pq.push(v[i].second);
            ans = max(ans,(long long)sum*mini);
        }
        
        
        for(int i = k;i<n;i++){
            pq.push(v[i].second);
            sum += v[i].second;
            sum -= pq.top(); pq.pop();
            ans = max(ans,(long long)v[i].first*sum);
            
        }
        return ans % M;
    }
};