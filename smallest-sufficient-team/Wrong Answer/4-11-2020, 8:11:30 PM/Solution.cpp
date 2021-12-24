// https://leetcode.com/problems/smallest-sufficient-team

class Solution {
public:
    map<string,int> m1;
    vector<int> p;
    int REQ = 0;
    int MS;
    int N;
    int FANS = 0;
    int bits = 1e9;
    int solve(int cnt,int mask,int group){
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
        
        int found =(( (1<<MS) - 1) ^ mask) & p[cnt];
        // cout << mask << " " << p[cnt] << " "<< found << endl;
        int newm = 0;
        if(found){
            newm = mask | p[cnt];
            return min(solve(cnt + 1,mask,group),1 + solve(cnt + 1,newm,group|=(1<<cnt)));
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
            int temp = 0;
            for(auto s : v){
                temp |= (1 << (m1[s]-1));
            }
            p.push_back(temp);
            temp = 0;
        }
        
        for(string s :rs){
            REQ |= (1 << (m1[s]-1));
        }

        // cout << "SOLVE : " << solve(0,0,0) << endl;
        // cout << "FANS : " << FANS << endl;
        
        vector<int> uans;
        for(int i = 0;i<MS;i++){
            if((FANS & (1 << i)) >=1) {
                uans.push_back(i);
            }
        }
        return uans;
    }
};