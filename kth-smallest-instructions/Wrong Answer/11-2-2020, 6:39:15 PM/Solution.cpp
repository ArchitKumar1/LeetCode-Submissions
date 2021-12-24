// https://leetcode.com/problems/kth-smallest-instructions

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        
        int MAXN = 20;
        long long int ncr[MAXN][MAXN];
        
        for(int i = 1;i<MAXN;i++){
            ncr[i][0] = ncr[i][i] = 1;
            for(int j = 1;j<i;j++){
                ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
            }
        }
        
        int N = destination[0] ,M= destination[1];
        int L = N + M;
        
        
        auto ranker= [&](int a,int b){
            return ncr[a][b];
        };
        string ans;
        
        int currank = 0;
        int cntH = M,cntV = N;
        
        for(int i = 0;i<L;i++){
            int rankH,rankV;
            if(cntH-1 > 0) rankH = ranker(cntH-1,cntV); else rankH =- 1;
            if(cntV-1 > 0) rankV = ranker(cntH,cntV-1); else rankV =- 1;
            
            int ranka = currank + rankH;
            int rankb = currank + rankV;
            
            if(rankH > 0 && rankV > 0){
                if(ranka <= k){
                    ans += 'H';
                    cntH -= 1;
                }else{
                    ans += 'V';
                    cntV -= 1;
                }
            }else if(rankH > 0){
                ans += 'H';
                cntH -= 1;
            }else{
                ans += 'V';
                cntV -= 1;
            }
            
        }
        return ans;
    }
};