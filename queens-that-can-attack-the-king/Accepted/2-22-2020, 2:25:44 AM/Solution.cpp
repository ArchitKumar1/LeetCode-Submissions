// https://leetcode.com/problems/queens-that-can-attack-the-king

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> all;
        map<vector<int>,int> m1;
        for(auto v : queens){
            m1[v] = 1;
        }
        int N = 10;
        
        for(int i = -1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i == 0 && j == 0) continue;
                for(int k = 1;k<N;k++){
                    vector<int> temp({king[0] + k*i,king[1] + k*j});
                    if(m1[temp]){
                        all.push_back(temp);
                        k = N+1;
                    }
                }
            }
        }
        return all;
    }
};