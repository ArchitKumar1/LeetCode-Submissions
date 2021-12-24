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
        int curr = W[i]-'A';
        int ans = 1e9;
        ans = min(ans,dist(curr,x) + solve(i+1,curr,y));
        ans = min(ans,dist(curr,y) + solve(i+1,x,curr));
        return ans;
    }
    int minimumDistance(string word) {
        W = word;
        n = W.size();
        int ans = 1e9;
        for(int i = 0;i<26;i++){
            for(int j = 0;j<26;j++){
                ans = min(ans,solve(0,i,j));
            }
        }
        return ans; 
    }
};