// https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool buddyStrings(string A, string B) {
        vector<pair<char,char>> V;
        int N = A.size();
        int M = B.size();
        
        if(N!=M) return 0;
        vector<int> same(26,0);
        
        for(int i = 0;i<N;i++){
            if(A[i]!=B[i]){
                V.emplace_back(A[i],B[i]);
            }else{
                same[A[i]-'a']++;
            }
        }
        if(V.size() == 0) {
            bool safe = 0;
            
            for(int c : same){
                if(c > 1){
                    safe = 1;
                }
            }
            return safe;
            
        }
        if(V.size()!=2){
            return 0;
        }
        if(V[0].first == V[1].second && V[0].second == V[1].first ) return 1;
        return 0;
    }
};