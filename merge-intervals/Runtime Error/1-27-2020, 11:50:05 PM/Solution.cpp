// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>> all;
        for(vector<int> v : intervals){
            all.push_back({v[0],v[1]});
        }
        sort(all.begin(),all.end());
        vector<vector<int>> ans;
        pair<int,int> curr = all[0];
        
        for(int  i =1;i<all.size();i++){
            if(all[i].first <=curr.second){
                curr.second = max(curr.second,all[i].second);
            }else{
                ans.push_back(vector<int>({curr.first,curr.second}));
                curr = all[i];
            }
        }
        ans.push_back(vector<int>({curr.first,curr.second}));
        return ans;
    }
};