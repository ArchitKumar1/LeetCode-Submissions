// https://leetcode.com/problems/describe-the-painting

#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){cout<<name<<" : "<<arg1<<endl;}
template<typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);}
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>&s) {
        int n = s.size();
        sort(s.begin(),s.end());
        
        vector<array<int,3>> v;
        for(auto x : s){
            int s = x[0],e = x[1],c = x[2];
            v.push_back({s,1,c});v.push_back({e,-1,c});
        }
        sort(v.begin(),v.end());
        vector<vector<long long>> ans;
        int back = -1;
        long long rs = 0;
        for(auto e : v){
            auto[d,t,c] = e;
           // trace(t,d,c,rs,back);
            if(back == -1){
                // first element starting
                back = d;
                rs += c;
            }else{
                if(back != d){
                    if(rs > 0){
                        ans.push_back({back,d,rs});
                       // trace("insert",back,d,rs);
                    }
                }
                if(t == -1)rs -= c;
                else rs += c;
                back = d;
            }
        }
        return ans;
    }
};