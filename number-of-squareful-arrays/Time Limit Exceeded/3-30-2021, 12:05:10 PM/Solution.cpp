// https://leetcode.com/problems/number-of-squareful-arrays

class Solution {
public:
    
    int N;
    int fans = 0;
    bool sq(int back,int val){
        int sum = back + val;
        int sqr = sqrt(sum);
        return sqr*sqr == sum;
    }
    map<vector<int>,int> m1;
    
    void count(vector<int>& A,vector<int>& avail,vector<int> curr,int cnt,int back){
            
        if(cnt == A.size()){
            if(m1[curr] != 1){
                fans++;
            }
            m1[curr] = 1; 
        }
        for(int i = 0;i < N;i++){
            if(avail[i] == 1 ){
                avail[i] = 0;
                if(back == -1 || sq(back,A[i])){
                    curr.push_back(A[i]);
                    count(A,avail,curr,cnt+1,A[i]); 
                    curr.pop_back();
                }
                avail[i] = 1;
            }
        }
        
    }
    int numSquarefulPerms(vector<int>& A) {
        N = A.size();
        vector<int> avail(N,1);
        count(A,avail,vector<int>({}),0,-1);
        return fans;
    }
};