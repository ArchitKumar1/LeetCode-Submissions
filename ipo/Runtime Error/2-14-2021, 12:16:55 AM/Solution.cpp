// https://leetcode.com/problems/ipo

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& p, vector<int>& c) {
        
        int n = p.size();
        
        vector<pair<int,int>> v;
        for(int i = 0;i<n;i++){
            v.push_back({c[i],p[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<pair<int,int>> pq;
        
        int i = 0;
        int count = 0;
        
        int ans = 0;
        for(int i = 0;i<n;){
            while(i < n && v[i].first <= W){
                pq.push({v[i].second,v[i].first});
                i++;
            }
            if(pq.size()){
                pair<int,int> p = pq.top();
                pq.pop();
                ans += p.first;
                W += p.first;
                count++; 
            }
        }
        int rem = k - count;
        while(rem--){
            if(!pq.size()) continue;
            pair<int,int> p = pq.top();
            pq.pop();
            ans += p.first;
        }
        return ans;
        
    }
};