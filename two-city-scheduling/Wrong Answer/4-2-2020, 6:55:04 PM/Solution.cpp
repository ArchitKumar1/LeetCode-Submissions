// https://leetcode.com/problems/two-city-scheduling

class Solution {
public:

    int twoCitySchedCost(vector<vector<int>>& costs) {
         int n =costs.size();
         int cost = 0;
         vector<int> v1,v2;
        for(auto v : costs){
            if(v[0] < v[1]){
                cost += v[0];
                v1.push_back(v[1]);
            }else{
                cost += v[1];
                v2.push_back(v[0]);
            }
        }
        sort(v1.rbegin(),v1.rend());
        sort(v2.rbegin(),v2.rend());
        if(v1.size() < v2.size()){
            swap(v1,v2);
        }
        while(v1.size() > n/2){
            cost += *v1.begin();
            v1.erase(v1.begin());
        }
        return cost;
         
    }
};