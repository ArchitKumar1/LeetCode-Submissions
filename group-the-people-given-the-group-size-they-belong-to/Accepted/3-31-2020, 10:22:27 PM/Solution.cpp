// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
         vector<vector<int>> ans;
         vector<vector<int>> pool(600);
        int i = 0;
        for(int c:g ){
            pool[c].push_back(i++);
            if(pool[c].size() == c){
                ans.push_back(pool[c]);
                pool[c].clear();
            }
        }
        return ans;
    }
};