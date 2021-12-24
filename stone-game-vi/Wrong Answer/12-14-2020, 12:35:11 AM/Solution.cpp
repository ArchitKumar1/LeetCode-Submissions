// https://leetcode.com/problems/stone-game-vi

class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        vector<pair<int,int>> v;
        int n = a.size();
        for(int i = 0;i<n;i++){ 
            v.emplace_back(a[i]+b[i],i);
        }
        sort(v.rbegin(),v.rend());
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(i%2 == 0){
                ans += a[v[i].second];
            }else{
                ans += b[v[i].second];
            }
        }
        if(ans > 0) return 1;
        if(ans == 0) return 0;
        if(ans < 0) return -1;
        return 1;
    }
};