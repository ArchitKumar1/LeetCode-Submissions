// https://leetcode.com/problems/grid-illumination

class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        map<int,int> r,c,d1,d2;
        
        for(auto v : lamps){
            r[v[0]] = 1;
            c[v[1]] = 1;
            d1[v[0] + v[1]] = 1;
            d2[v[0] - v[1]] = 1;
        }
        vector<int> ans;
        for(auto v : queries){
            // cout << r[v[0]]  << "  " << c[v[1]] << " " << d1[v[0] + v[1]] << " " << d2[v[0] - v[1]] << endl;
            int value = (r[v[0]] >=  1 && c[v[1]] >= 1) || d1[v[0] + v[1]] >= 1 || d2[v[0] - v[1]] >= 1;
            ans.push_back(value);
        }
        return ans;
    }
};