// https://leetcode.com/problems/jump-game-iv

class Solution {
public:
    
    
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(n,1e8);
        queue<pair<int,int>> qq;
        qq.push({0,0});
        while(qq.size()){
            int temp =qq.front().first;
            int tcnt = qq.front().second;
            qq.pop();
            if(cnt[temp] < tcnt) continue;
            cnt[temp] = tcnt;
            if( temp + 1 < n){
                qq.push({temp+1,tcnt+1});
            }
            if( temp - 1 >= 0){
                qq.push({temp-1,tcnt+1});
            }
            for(int i =0 ;i<n;i++){
                if(arr[i] == arr[temp]){
                    qq.push({i,tcnt+1});
                }
            }
            if(temp == n-1)break;
        }

        return cnt[n-1];
    }
};