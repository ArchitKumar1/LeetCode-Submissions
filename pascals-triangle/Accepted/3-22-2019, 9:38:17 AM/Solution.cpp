// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i == 0){
                vector<int> x(1,1);
                ans.push_back(x);
                continue;
            }
            if(i == 1){
                vector<int> x(2,1);
                ans.push_back(x);
                continue;
            }
            vector<int> x;
            x.push_back(1);
            for(int j=0;j<i-1;j++){
                x.push_back(ans[i-1][j] + ans[i-1][j+1]);
            }
            x.push_back(1);
            ans.push_back(x);
        }
        return ans;
    }
};