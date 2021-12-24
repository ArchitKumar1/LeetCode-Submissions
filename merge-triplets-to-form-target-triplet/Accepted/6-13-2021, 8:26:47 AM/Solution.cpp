// https://leetcode.com/problems/merge-triplets-to-form-target-triplet

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& ta) {
        vector<vector<int>> trips;
        for(auto t : triplets){
            bool safe = 1;
            for(int i = 0;i<3;i++){
                safe&=(t[i]<=ta[i]);
            }
            if(safe) trips.push_back(t);
        }
        vector<int> ans(3,0);
        for(auto t : trips){
            for(int i = 0;i<3;i++){
                ans[i] = max(ans[i],t[i]);
            }
        }
        return ans == ta;
    }
};