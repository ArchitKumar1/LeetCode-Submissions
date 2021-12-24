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
        priority_queue<int> pq;
        
        int i = 0;
        int count = 0;
        
        int ans = 0;
        while(k--){
            while(i < n && v[i].first <= W){
                pq.push(v[i++].second);
            }
            if(pq.size()){
                int p = pq.top();
                pq.pop();
                W += p;
                
            }
        }
        return W;
        
    }
};