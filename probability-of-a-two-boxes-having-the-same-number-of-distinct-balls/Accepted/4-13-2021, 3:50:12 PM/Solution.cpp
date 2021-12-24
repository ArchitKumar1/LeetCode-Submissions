// https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls

template<class T> ostream& operator<<(ostream &os,vector<T> V){os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";}

#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){cout<<name<<" : "<<arg1<<endl;}
template<typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);}
class Solution {
public:
    
    const int  fact[7]= {1,1,2,6,24,120,720};
    int n;
    double a = 0;
    double b = 0;
    int total = 0;
    vector<int> nums;
    double perm(vector<int> v){
        double ans = 1;
        int k = 1;            
        for(int c : v ){
            for(int i = 1;i<=c;i++){
                ans *= k++;
                ans /= i;
            }
        };
        return ans;
    }
    int dist(vector<int> &v){
        return v.size() - count(v.begin(),v.end(),0);
    }
    vector<int> get_other(vector<int> &v){
        vector<int> other = nums;
        for(int i = 0;i<nums.size();i++){
            other[i]-= v[i];
        }
        return other;
    }
    bool check(vector<int> &v){
        int c1 = dist(v);
        vector<int> other = get_other(v);
        int c2 = dist(other);
        return c1 == c2;
    }
    void comp(int pos,vector<int> v){
        int sum = 0;
        for(int c : v) sum+= c;
            if(sum*2 > total) return;
        if(pos == n){
            int sum = 0;
            for(int c : v) sum+= c;
            if(sum*2 != total) return;
            double p1 = perm(v);
            double p2 =  perm(get_other(v));
            b+= p1*p2;
            if(check(v)) a += p1*p2;
            return;
        }
        for(int i = 0;i<=nums[pos];i++){
            v[pos] = i;
            comp(pos+1,v);
        }
    };
    double getProbability(vector<int> nums1) {
        nums = nums1;
        n =  nums.size();
        for(int c : nums) total+= c;
        comp(0,vector<int>(n));
        return (double)a/b;
    }
};