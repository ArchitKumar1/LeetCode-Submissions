// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        map<int,int> m1;
        for(int c : chips) m1[c]++;
        vector<pair<int,int>> v;
        for(auto x :m1){
            if(x.second > 0) v.push_back(x);
        }
        sort(v.begin(),v.end());
        int ans = INT_MAX;
        int n = v.size();
        for(int i = 0;i<n;i++){
            int tans = 0;
            for(int j=0;j<n;j++){
                if(j!=i) tans += v[j].second*(abs(v[i].first-v[j].first)&1);  
            }
            cout << tans << " " << endl;
            ans = min(ans,tans);
        }
        return ans;
        
    }
};