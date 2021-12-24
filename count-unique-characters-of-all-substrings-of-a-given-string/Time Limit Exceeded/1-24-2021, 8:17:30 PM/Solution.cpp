// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string

#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){cout<<name<<" : "<<arg1<<endl;}
template<typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);}

class Solution {
public:
    int uniqueLetterString(string s) {
        
        int MOD = 1e9+7;
        long long int ans = 0;
        
        vector<vector<int>> cnt(26);
        
        int n = s.size();
        for(int i = 0;i<n;i++){
            cnt[s[i]-'A'].push_back(i);
        }
        
        for(int i= 0;i<26;i++){
            for(int j = 0;j<cnt[i].size();j++){
                long long int L = (j==0 ? cnt[i][j] +1: cnt[i][j] - cnt[i][j-1]);
                long long int R = (j+1 == cnt[i].size() ?  n - cnt[i][j] : cnt[i][j+1]-cnt[i][j]);
                trace(i,j,L,R,cnt[i][j]);
                (ans += (L*R) %MOD)%= MOD;
            }
        }
        return ans;
    }
};