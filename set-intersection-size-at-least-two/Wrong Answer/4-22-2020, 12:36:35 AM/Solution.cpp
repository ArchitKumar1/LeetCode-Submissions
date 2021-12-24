// https://leetcode.com/problems/set-intersection-size-at-least-two

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& it) {
        vector<vector<int>> v1(it.begin(),it.end());
        vector<vector<int>> v2(it.begin(),it.end());
        
        sort(v1.begin(),v1.end(),[&]                         (vector<int>a,vector<int>b){
            return a[1] < b[1];
        });
            
            sort(v2.begin(),v2.end(),[&]                         (vector<int>a,vector<int>b){
            return a[0] < b[0];
        });
        
        int y = (*v2.rbegin())[0] + 1;
        int x = (*v1.begin())[1] - 1;
        
        return y-x + 1;
        
    }
};