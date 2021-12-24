// https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers

class Solution {
public:
    string W;
    int n;
    int dist(int x,int y){
        return abs(y/n - x/n) + abs(y%n - x%n);
    }
    int solve(int i,int x,int y){
        if(i == n) return 0;
        int ans = 1e9;

        int curr = W[i]-'A';
        ans = min(ans,x ==-1 ? dist(curr,x): 0 + solve(i+1,curr,y));
        ans = min(ans,y ==-1 ? dist(curr,y): 0 + solve(i+1,x,curr));
        
        
        return ans;
    }
    int minimumDistance(string word) {
        W = word;
        n = W.size();
        int ans = solve(0,-1,-1);
        return ans; 
    }
};