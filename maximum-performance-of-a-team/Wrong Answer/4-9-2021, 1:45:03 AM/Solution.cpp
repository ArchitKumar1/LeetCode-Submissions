// https://leetcode.com/problems/maximum-performance-of-a-team

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.emplace_back(efficiency[i],speed[i]);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int mini = INT_MAX;
        int sum  = 0; 
        int ans = 0;
        for(int i = 0;i<k;i++){
            mini = min(mini,efficiency[i]);
            sum += speed[i];
            pq.push(speed[i]);
        }
        ans = max(ans,sum*mini);
        
        for(int i = k+1;i<n;i++){
            mini = min(mini,efficiency[i]);
            
            sum += speed[i];
            sum -= pq.top();
            ans = max(ans,mini*sum);
            pq.push(speed[i]);
        }
        return ans;
    }
};