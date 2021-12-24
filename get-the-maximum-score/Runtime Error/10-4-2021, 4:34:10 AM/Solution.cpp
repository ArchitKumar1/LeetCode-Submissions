// https://leetcode.com/problems/get-the-maximum-score

template<class T> ostream& operator<<(ostream &os, set<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class T> ostream& operator << (ostream& os, multiset<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {os << "{ ";for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";return os<<"}";}
template<class T> ostream& operator<<(ostream &os,vector<T> V){os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";}

//read
template<class T> istream& operator>>(istream &is,vector<T> &V){for(auto &x : V) is >> x;return is;}
template<class T> istream& operator>>(istream &is,vector<vector<T>> &V){for(auto &x : V) is >> x;return is;}

//output 
void print(){cout << endl;}template <typename T, typename... Types> void print(T var1, Types... var2){cout << var1 << " ";  print(var2...);}
//input 
void read(){}template <typename T, typename... Types> void read(T& var1, Types&... var2){cin >> var1; read(var2...);}


#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){cout<<name<<" : "<<arg1<<endl;}
template<typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);}



class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1,s2,s3;
        map<int,int> dp;
        for(auto x : nums1) s1.insert(x),s3.insert(x);
        for(auto x : nums2) s2.insert(x),s3.insert(x);
        
        auto in = [&](set<int> &s ,int v) -> bool{
            return s.find(v) != s.end();
        };
        auto solve = [&](set<int> &s,int V,int &ans){
            if(!in(s,V)) return;
            auto it1 = s.find(V);
            if(it1 != s.begin()){
                it1--;
                int k = *it1;
                // trace(V,k);
                ans = max(ans,dp[k]);
            }
            
        };
        int fans = 0;
        for(auto it = s3.begin();it != s3.end();it++){
            int K =  *it;
            int ans = 0;
            solve(s1,K,ans);
            solve(s2,K,ans);
            dp[K] = ans + K;
            // trace(K,ans,dp);
            fans = max(fans,dp[K]);
        }
        return fans;
    }
};