// https://leetcode.com/problems/kth-smallest-instructions

#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){
		const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}

class Solution {
#define LL long long int
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        
        LL MAXN = 20;
        LL ncr[MAXN][MAXN];
        memset(ncr,0,sizeof(ncr));
        for(int i = 1;i<MAXN;i++){
            ncr[i][0] = ncr[i][i] = 1;
            for(int j = 1;j<i;j++){
                ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
            }
        }
        
        LL N = destination[0] ,M= destination[1];
        LL L = N + M;
        
        
        auto ranker= [&](LL a,LL b){
            trace(a,b);
            return ncr[a+b][b];
            assert(a>=0);assert(b>=0);
            
        };
        string ans;
        
        LL currank = 0;
        LL cntH = M,cntV = N;
        
        for(int i = 0;i<L;i++){
            LL rankH,rankV;
            trace(cntH,cntV);
            bool f1 = 0,f2= 0;
            if((cntH-1) >= 0){
                rankH = ranker(cntH-1,cntV);
                f1 = 1;
            } 
            if((cntV-1)>= 0){
                rankV = ranker(cntH,cntV-1);
                f2 = 1;
            } 
            
            trace(i,cntH,cntV,rankH,rankV);
            if(f1 && f2){
                if( k<= rankH){
                    ans += 'H';
                    cout << ans << endl;
                    cntH -= 1;
                }else{
                    ans += 'V';
                    cout << ans << endl;
                    k -= rankH;
                    cntV -= 1;
                }
            }else if(f1){
                ans += 'H';
                cout << ans << endl;
                cntH -= 1;
            }else if(f2){
                ans += 'V';
                cout << ans << endl;
                k -= rankH;
                cntV -= 1;
            }else{
            cout << "hola " << endl;
            }
            trace(ans);
            
        }
        return ans;
    }
};