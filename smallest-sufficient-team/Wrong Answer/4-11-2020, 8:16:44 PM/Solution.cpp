// https://leetcode.com/problems/smallest-sufficient-team

class Solution {
public:
    map<string,long long int> m1;
    vector<long long int> p;
    long long int REQ = 0;
    int MS;
    long long int N;
    long long int FANS = 0;
    long long int bits = 1e9;
    long long int solve(long long int cnt,long long int mask,long long int group){
        // cout << cnt << " " << mask << endl;
        if(cnt == N){
            if(mask!=REQ) return 1e9;
            
        }
        if(mask == REQ) {
            int currbits = __builtin_popcount(group);
            if(currbits < bits){
                bits = currbits;
                FANS = group;
            }
            return 0;
        }
        
        long long int found =(( (1LL<<MS) - 1) ^ mask) & p[cnt];
        // cout << mask << " " << p[cnt] << " "<< found << endl;
        long long int newm = 0;
        if(found){
            newm = mask | p[cnt];
            return min(solve(cnt + 1,mask,group),1 + solve(cnt + 1,newm,group|=(1LL<<cnt)));
        }else{
            return solve(cnt+1,mask,group);
        }    
    }
    vector<int> smallestSufficientTeam(vector<string>& rs, vector<vector<string>>& people) {
        
        N = people.size();
        for(auto v : people){
            for(string s : v){
                if(m1[s] == 0){
                    m1[s] = ++MS;
                }
            }
        }
        
        for(auto v : people){
            long long int temp = 0LL;
            for(auto s : v){
                temp |= (1LL << (m1[s]-1));
            }
            p.push_back(temp);
            temp = 0LL;
        }
        
        for(string s :rs){
            REQ |= (1 << (m1[s]-1));
        }

        cout << "SOLVE : " << solve(0LL,0LL,0LL) << endl;
        cout << "FANS : " << FANS << endl;
        
        vector<int> uans;
        for(int i = 0;i<N;i++){
            if((FANS & (1LL << i)) >=1) {
                uans.push_back(i);
            }
        }
        return uans;
    }
};