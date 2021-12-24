// https://leetcode.com/problems/pizza-with-3n-slices

class Solution {
    int dp[1010][1010];
    
public:
    
    vector<int> sl;
    
    int get(int i,int j){
        if( j < i) return 0;
        // if(dp[i][j] !=-1){
        //     return dp[i][j];
        // }
        if(j-i <= 2){
            int ans = 0;
            for(int x = i;x<=j;x++){
                ans = max(ans,sl[x]);
            }
            return dp[i][j] = ans;
            
        }
        int ans =0;
        ans = max(sl[i] + get(i+2,j-1),sl[j] + get(i+1,j-2));
        for(int x = i+1;x<=j-1;x++){
            ans = max(ans,get(i,x-2) + sl[x] + get(j+2,j));
        }
        return dp[i][j] = ans;
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        for(int c : slices){
            sl.push_back(c);
        }
        for(int c : slices){
            sl.push_back(c);
        }
        
        int fans = 0;
        for(int i = 0;i<n;i++){
            memset(dp,-1,sizeof(dp));
            int x = get(i,n+i-1) ;
            fans = max(fans,x);
        }
        return fans;
        
    }
};