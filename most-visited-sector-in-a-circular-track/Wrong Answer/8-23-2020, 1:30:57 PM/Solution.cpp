// https://leetcode.com/problems/most-visited-sector-in-a-circular-track

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        
        vector<pair<int,int>> cnt(n,{0,0});
        for(int i= 0;i<n;i++){
            cnt[i].second = i;
        }
        for(int i = 0;i+1<n;i++){
            int x = rounds[i];
            int y = rounds[i+1];
            
            for(int k = x;k<=y;k++){
                cnt[k].first++;
            }
        }
        sort(cnt.begin(),cnt.end());
        vector<int>ans;
        
        int mv = INT_MIN;
        for(auto x : cnt ){
            mv =max(mv,x.first);
        }
        
        for(auto x : cnt ){
            if(x.first == mv){
                ans.push_back(x.second);
            }
        }
        return ans;
            
    }
};