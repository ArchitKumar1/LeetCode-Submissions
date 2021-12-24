// https://leetcode.com/problems/jump-game-iv

class Solution {
public:
    
    vector<int> cnt,vis,ARR;
    int N ;
    
    void solve(int i,int steps){
        if(i < 0 || i>=N)return;
        if(cnt[i] < steps) return;
        cnt[i] = steps;
        solve(i+1,steps+1);
        solve(i-1,steps+1);
        for(int I =0 ;I<N;I++){
            if(i!=I && ARR[i] == ARR[I]){
                solve(I,steps+1);
            }
        }
    }
    int minJumps(vector<int>& arr) {
        int n =arr.size();
        N = n;
        ARR = arr;
        cnt.assign(n,1e9);
        vis.assign(n,0);
        cnt[0]= 0 ;
        solve(0,0);
        return cnt[n-1];
    }
};