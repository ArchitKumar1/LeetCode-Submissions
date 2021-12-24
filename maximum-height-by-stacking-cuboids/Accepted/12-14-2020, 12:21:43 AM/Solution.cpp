// https://leetcode.com/problems/maximum-height-by-stacking-cuboids

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        
        vector<vector<int>> all;
        int pos = 0;
        for(auto x : cuboids){
            sort(x.begin(),x.end());
            do{
                all.push_back({x[0],x[1],x[2],pos});
            }while ( next_permutation(x.begin(),x.end()));
            pos++;
        }
        sort(all.rbegin(),all.rend());
        
        
        auto safe = [&](int i,int j) -> bool{
            if(all[i][3] == all[j][3]) return 0;
            for(int k = 0;k<3;k++){
                if(all[i][k] > all[j][k]) return 0;
            }
            return 1;
        };
        int n = all.size();
        vector<int> dp(n+1,0);
        for(int i = 0;i<n;i++){
            dp[i] = all[i][2];
            for(int j = 0;j<i;j++){
                if(safe(i,j)){
                    dp[i]= max(dp[i],dp[j] + all[i][2]);
                }
            }
        }

        return *max_element(dp.begin(),dp.end());
        
    }
};