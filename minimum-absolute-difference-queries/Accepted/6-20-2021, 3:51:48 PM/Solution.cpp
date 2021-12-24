// https://leetcode.com/problems/minimum-absolute-difference-queries

class Solution {
public:
    
    int a[102][100005];
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        for(int i= 0;i < n;i++){
            a[nums[i]][i+1]++;
        }
        for(int x = 1;x <= 100;x++){
            for(int i= 1;i <= n;i++){
                a[x][i] +=  a[x][i-1];
            }
        }
        int q = queries.size();
        vector<int> res(q);
        int pos = 0;
        for(auto query : queries){
            int l = query[0], r = query[1];
            int back = -1e9;
            int ans = 1e9;
            for(int x = 1;x <= 100;x++){
                int cnt = a[x][r+1]-a[x][l];
                if(cnt > 0){
                    // cout << pos <<  " " << x << " " << cnt << endl;
                    ans = min(ans,x - back);
                    back = x;
                }
            }
            // cout << ans << " BACK " << " "<< back << " " << pos << endl;
            
            if(ans < 1e9) res[pos] = ans;
            else res[pos]= -1;
            pos++;
        }
        return res;
        
    }
};