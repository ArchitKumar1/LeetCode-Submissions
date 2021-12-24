// https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& r, int v, int p, int d) {
        vector<vector<int>> all;
        for(auto v1 : r){
            if((v ? v1[2] : 1) && v1[3] <= p && v1[4] <=d){
                all.push_back(v1);
            }
        }
        sort(all.begin(),all.end(),[&](vector<int> a,vector<int> b){
            if(a[1] != b[1] ){
                return a[1] > b[1];
            }else{
                return a[0] > b[0];
            }
        });
        vector<int> ans;
        for(auto v : all){
            ans.push_back(v[0]);
        }
        return ans;
    }
    
};