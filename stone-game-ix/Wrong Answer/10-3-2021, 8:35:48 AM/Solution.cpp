// https://leetcode.com/problems/stone-game-ix

class Solution {
public:
    
    bool solve(int a,int b, int c, int sum,int turn){
        // cout << a << " " << b << " " << c << " "<< sum << " " << turn << endl;
        bool ans = 0; 
        if(turn == 0){
            // alice
            if(sum %3 == 1){
                //rem 1 can choose only 1 and 3;
                if(a > 0) ans |= !solve(a-1,b,c,(sum+1)%3,turn^1);
                if(c > 0) ans |= !solve(a,b,c-1,(sum+2)%3,turn^1);

            }else if(sum %3 == 2){
                //rem 2 can choose only 2 and 3;
                if(b > 0) ans |= !solve(a,b-1,c,(sum+2)%3,turn^1);
                if(c > 0) ans |= !solve(a,b,c-1,(sum+3)%3,turn^1);
            }else if(sum %3 == 0){
                if(a > 0) ans |= !solve(a-1,b,c,(sum+1)%3,turn^1);
                if(b > 0) ans |= !solve(a,b-1,c,(sum+2)%3,turn^1);
            }
        }else{
            // bob
            if(a == 0 && b == 0 && c == 0) return true;
            if(sum %3 == 1){
                //rem 1 can choose only 1 and 3;
                if(a > 0) ans |= !solve(a-1,b,c,(sum+1)%3,turn^1);
                if(c > 0) ans |= !solve(a,b,c-1,(sum+2)%3,turn^1);

            }else if(sum %3 == 2){
                //rem 2 can choose only 2 and 3;
                if(b > 0) ans |= !solve(a,b-1,c,(sum+2)%3,turn^1);
                if(c > 0) ans |= !solve(a,b,c-1,(sum+3)%3,turn^1);
            }else if(sum %3 == 0){
                if(a > 0) ans |= !solve(a-1,b,c,(sum+1)%3,turn^1);
                if(b > 0) ans |= !solve(a,b-1,c,(sum+2)%3,turn^1);
            }
        }
        // cout << a << " " << b << " " << c << " "<< sum << " " << turn << " " << ans << endl;

        return ans;
    }
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3,0);
        for(auto &s : stones) cnt[s%3]++;
        
        cout << endl;
        return solve(cnt[1],cnt[2],cnt[0],0,0);
        
        
    }
};