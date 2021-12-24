// https://leetcode.com/problems/orderly-queue

class Solution {
public:
    string orderlyQueue(string S, int K) {
        if(K == 1){
            string ans = S;

            for(int i =0;i < S.size();i++){
                rotate(S.begin(),S.begin()+1,S.end());
                ans = min(ans,S);
            }
            return ans;
        }else{
            sort(S.begin(),S.end());
            return S;
        }
    }
};