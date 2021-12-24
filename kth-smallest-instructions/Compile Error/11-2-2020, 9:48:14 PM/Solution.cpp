// https://leetcode.com/problems/kth-smallest-instructions

class Solution {
#define LL long long int
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        
        LL MAXN = 31;
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
        
        
        auto ranker= [&](LL a,LL b) -> LL{
            return ncr[a+b][a];
            
        };
        string ans;
        
        LL currank = 0;
        LL cntH = M,cntV = N;
        
        for(int i = 0;i<L;i++){
            LL rankH,rankV;
            bool f1 = 0,f2= 0;
            if((cntH-1) >= 0){
                rankH = ranker(cntH-1,cntV);
                f1 = 1;
            } 
            if((cntV-1)>= 0){
                rankV = ranker(cntH,cntV-1);
                f2 = 1;
            } 
            if(f1 && f2){
                if( k<= rankH){
                    ans += 'H';
                    cntH -= 1;
                }else{
                    ans += 'V';
                    k -= rankH;
                    cntV -= 1;
                }
            }else if(f1){
                ans += 'H';
                cntH -= 1;
            }else if(f2){
                ans += 'V';
                k -= rankH;
                cntV -= 1;
            }
            trace(ans);
            
        }
        return ans;
    }
};