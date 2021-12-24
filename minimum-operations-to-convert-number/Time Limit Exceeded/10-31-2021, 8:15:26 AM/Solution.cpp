// https://leetcode.com/problems/minimum-operations-to-convert-number

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n= nums.size();
        int ans = 0;
        bool f = 0;
        
        queue<int> q;
        q.push(start);
        unordered_map<int,int> cnt;
        
        while(q.size()){
            int L = q.size();
            ans += 1;
            for(int x = 0;x < L; x++){
                int val = q.front(); q.pop();
                // cout << val << endl;
                if(cnt[val] == 1) continue;
                cnt[val] = 1;
                if(val == goal){
                    f = 1;
                    q = queue<int>();
                    break;
                }
                if(val < 0 || val > 1000) continue;
                for(int i = 0; i < n;i++){
                    {
                       int nval = val + nums[i];
                       q.push(nval);
                    } 
                    {
                     int nval = val - nums[i];
                       q.push(nval);
                    } 
                    {
                       int nval = val ^ nums[i];
                       q.push(nval);
                    } 
                }
                
            }
            
        }
        if(!f) return -1;
        return ans-1;
    }
};