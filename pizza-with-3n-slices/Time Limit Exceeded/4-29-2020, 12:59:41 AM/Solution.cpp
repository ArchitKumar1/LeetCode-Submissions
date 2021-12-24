// https://leetcode.com/problems/pizza-with-3n-slices

class Solution {
    int dp[1010][1010];
    
public:
    
    vector<int> sl;
    int N ;
    int get(int i,int cnt,int end){
        if(i > end || cnt == N) return 0;
        int ans =0;
        ans = max(sl[i] + get(i+2,cnt+1,end) , get(i+1,cnt,end));
        return ans;
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        N = n/3;
        for(int c : slices){
            sl.push_back(c);
        }
        memset(dp,-1,sizeof(dp));
        int fans = get(0,0,n-2);
        
        memset(dp,-1,sizeof(dp));
        fans = max(fans,get(1,0,n-1));
        
        return fans;
        
    }
};