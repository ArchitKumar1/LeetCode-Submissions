// https://leetcode.com/problems/stone-game-vi

class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        vector<int> v;
        int n = a.size();
        for(int i = 0;i<n;i++){ 
            v.push_back(a[i]+b[i]);
        }
        sort(v.rbegin(),v.rend());
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(i%2 == 0){
                ans += a[i];
            }else{
                ans += b[i];
            }
        }
        if(ans > 0) return 1;
        if(ans == 0) return 0;
        if(ans < 0) return -1;
        return 1;
    }
};