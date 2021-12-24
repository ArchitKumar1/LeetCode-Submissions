// https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers

class Solution {
public:
    string W;
    int n;
    int dist(int x,int y){
        return abs(y/6 - x/6) + abs(y%6 - x%6);
    }
    int solve(int i,int x,int y){
        // cout << i << " " << x << " " << y << endl;
        if(i == n) return 0;
        int ans = 1e9;

        int curr = W[i]-'A';
        ans = min(ans,(x ==-1 ? dist(curr,x): 0) + solve(i+1,curr,y));
        ans = min(ans,(y ==-1 ? dist(curr,y): 0 )+ solve(i+1,x,curr));
        
        // cout << ans << " " << i << " " << x << " " << y << endl;
        
        return ans;
    }
    int minimumDistance(string word) {
        W = word;
        n = word.size();
        cout << dist(0,7) << endl;
        int ans = solve(0,-1,-1);
        
        return ans; 
    }
};