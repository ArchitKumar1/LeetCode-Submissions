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
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        
        int MAXN = 20;
        long long int ncr[MAXN][MAXN];
        memset(ncr,1,sizeof(ncr));
        for(int i = 1;i<MAXN;i++){
            ncr[i][0] = ncr[i][i] = 1;
            for(int j = 1;j<i;j++){
                ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
            }
        }
        
        int N = destination[0] ,M= destination[1];
        int L = N + M;
        
        
        auto ranker= [&](int a,int b){
            return ncr[a+b][b];
        };
        string ans;
        
        int currank = 0;
        int cntH = M,cntV = N;
        
        for(int i = 0;i<L;i++){
            int rankH,rankV;
            if(cntH-1 >= 0) rankH = ranker(cntH-1,cntV); else rankH =0;
            if(cntV-1 >= 0) rankV = ranker(cntH,cntV-1); else rankV =0;
            
            int ranka = rankH;
            int rankb = ranka + rankV;
            
            trace(i,cntH,cntV,ranka,rankb,ranker(cntH-1,cntV),ranker(cntH,cntV-1));
            if(rankH > 0 && rankV > 0){
                if( k<= ranka){
                    ans += 'H';
                    cntH -= 1;
                }else{
                    ans += 'V';
                    k -= ranka;
                    cntV -= 1;
                }
            }else if(rankH > 0){
                ans += 'H';
                cntH -= 1;
            }else{
                ans += 'V';
                k -= ranka;
                cntV -= 1;
            }
            trace(ans);
            
        }
        return ans;
    }
};