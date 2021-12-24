// https://leetcode.com/problems/jump-game-iv

class Solution {
public:
    
    
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(n,0);
        vector<int> vis(n,0);
        queue<pair<int,int>> qq;
        qq.push({0,0});
        while(qq.size()){
            int temp =qq.front().first;
            int tcnt = qq.front().second;
            qq.pop();
            vis[temp] = 1;
            cnt[temp] = tcnt;
            if( temp + 1 < n && vis[temp+1] == 0){
                qq.push({temp+1,tcnt+1});
            }
            if( temp - 1 >= 0 && vis[temp-1] == 0){
                qq.push({temp-1,tcnt+1});
            }
            for(int i =0 ;i<n;i++){
                if(arr[i] == arr[temp] && i!= temp && vis[i] == 0){
                    qq.push({i,tcnt+1});
                }
            }
            if(temp == n-1)break;
        }

        return cnt[n-1];
    }
};