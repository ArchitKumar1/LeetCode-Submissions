// https://leetcode.com/problems/number-of-squareful-arrays

class Solution {
public:
    
    int N;
    bool sq(int back,int val){
        int sum = back + val;
        int sqr = sqrt(sum);
        return sqr*sqr == sum;
    }
    int count(vector<int>& A,vector<int>& avail,int cnt,int back){

        if(cnt == A.size()){
            return 1;
        }
        
        int ans = 0;
        for(int i = 0;i < N;i++){
            if(avail[i] == 1 ){
                avail[i] = 0;
                if(back == -1 || sq(back,A[i])){
                    ans += count(A,avail,cnt+1,A[i]); 
                }
                avail[i] = 1;
            }
        }
        return ans;
    }
    int numSquarefulPerms(vector<int>& A) {
        N = A.size();
        vector<int> avail(N,1);
        return count(A,avail,0,-1);
    }
};