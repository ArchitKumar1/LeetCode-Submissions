// https://leetcode.com/problems/most-visited-sector-in-a-circular-track

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        
        vector<pair<int,int>> cnt(n,{0,0});
        for(int i= 0;i<n;i++){
            cnt[i].second = i;
        }
        for(int i = 0;i+1<rounds.size();i++){
            int x = rounds[i]-1;
            int y = rounds[i+1]-1;
            
            int k = x;
            
            while(k!=y){
                cout << k << endl;
                cnt[k].first++; 
                k = (k+1)%n;
            }
            if(i == rounds.size()-2){
                cnt[y].first++;
            }
        }
        vector<int>ans;
        
        int mv = INT_MIN;
        for(auto x : cnt ){
            cout << x.first << " " << x.second << endl;
            mv =max(mv,x.first);
        }
        
        for(auto x : cnt ){
            if(x.first == mv){
                ans.push_back(x.second+1);
            }
        }
        cout << endl;
        return ans;
            
    }
};