// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(intervals.size() == 0) return ans;
        vector<pair<int,int>> all;
        intervals.push_back(newInterval);
        for(vector<int> v : intervals){
            all.push_back({v[0],v[1]});
        }
        sort(all.begin(),all.end());
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