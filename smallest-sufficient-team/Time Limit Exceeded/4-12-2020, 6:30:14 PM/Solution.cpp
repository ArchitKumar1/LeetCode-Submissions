// https://leetcode.com/problems/smallest-sufficient-team

class Solution {
public:
    #define LL long long int
    string numtobin(long long int x){
        string s = "";
        while(x){
            s += ((x&1) ? "1" : "0");
            x>>=1;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    map<string,LL> m1;
    vector<LL> p;
    LL REQ = 0;
    LL MS;
    LL N;
    LL FANS = 0;
    LL bits = 1e9;
    vector<vector<int>>dp;
    LL solve(LL cnt,LL mask,LL group){
        if(dp[cnt][mask]!=-1) return dp[cnt][mask];
        LL subset = REQ|mask;
        // cout << cnt << " " << mask << " " << subset << " " << group <<  endl;
        
        if( subset == mask) {
            LL currbits = __builtin_popcountll(group);  
            if(currbits < bits){
                bits = currbits;
                FANS = group;
            }
            return 0;
            
        }
        if(cnt == N) return 1e9;
        
        LL found = (mask | p[cnt])!= mask;
        if(found){
            LL newm = mask | p[cnt];
            return dp[cnt][mask] = min(solve(cnt + 1,mask,group),1 + solve(cnt + 1,newm,group|=(1LL<<cnt)));
        }else{
            return dp[cnt][mask] = solve(cnt+1,mask,group);
        }    
    }
    vector<int> smallestSufficientTeam(vector<string>& rs, vector<vector<string>>& people) {
        dp = vector<vector<int>>(65,vector<int>((1<<21),-1));
        N = people.size();
        for(auto v : people){
            for(string s : v){
                if(m1[s] == 0){
                    m1[s] = ++MS;
                }
            }
        }
        
        for(auto v : people){
            LL temp = 0LL;
            for(auto s : v){
                temp |= (1LL << (m1[s]-1));
            }
            p.push_back(temp);
            temp = 0LL;
        }
        
        for(string s :rs){
            REQ |= (1LL << (m1[s]-1));
        }

        cout << "SOLVE : " << solve(0LL,0LL,0LL) << endl;
        cout << "FANS : " << FANS << endl;
        cout << "bits :"  << bits<< endl;
        
        vector<int> uans;
        for(int i = 0;i<N;i++){
            if((FANS & (1LL << i)) >=1) {
                uans.push_back(i);
            }
        }
        // 111001110101
        // 101001010101
        return uans;
    }
};