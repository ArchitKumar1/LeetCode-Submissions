// https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete

class Solution {
public:
    vector<int> ans;
    int F,S;
    void solve(int moves,vector<int> peeps){
        // cout << "moves" << " " << moves << endl;
        // for(int c : peeps){
        //     cout << c << " " ;
        // }
        // cout << endl;
        int n = peeps.size();
        int m = n/2;
        for(int i = 0;i<n/2;i++){
            if((peeps[i] == F && peeps[n-i-1] == S) || (peeps[n-i-1] == F && peeps[i] == S)){
                ans[0] = min(ans[0],moves);
                ans[1] = max(ans[1],moves);
                return;
            }
        }
        if(peeps.size() == 2){
            ans[0] = min(ans[0],moves);
            ans[1] = max(ans[1],moves);
            return;
        }
        
        for(int i = 0;i < 1 << m;i++){
            vector<int> npeeps(m + (n&1));
            vector<int> mark(n);
            for(int j = 0;j < m;j++){
                if(i>>j&1){
                    if(peeps[n-j-1] == F || peeps[n-j-1] == S){
                        mark[n-j-1] = 1;
                    }else{
                        mark[j] = 1;
                    }
                    
                }else{
                    if(peeps[j] == F || peeps[j] == S){
                        mark[j] = 1;
                    }else{
                        mark[n-j-1] = 1;
                    }
                }
            }
            if(n&1){
                mark[m] = 1;
            }
            // cout << "mark" << endl;
            // for(int c : mark){
            //     cout << c << " " ;
            // }
            // cout << endl;
            for(int i = 0,j = 0;i < n;i++){
                if(mark[i] == 1) npeeps[j++] = peeps[i];
            }
            // for(int c : peeps){
            //     cout << c << " " ;
            // }
            // cout << " : " ;
            // for(int c : npeeps){
            //     cout << c << " " ;
            // }
            // cout << endl;
            solve(moves+1,npeeps);
        }
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        F = firstPlayer, S= secondPlayer;
        ans = vector<int>({INT_MAX,INT_MIN});
        vector<int> peeps(n);
        iota(peeps.begin(),peeps.end(),1);
        solve(0,peeps);
        ans[0]++,ans[1]++;
        return ans;
    }
};