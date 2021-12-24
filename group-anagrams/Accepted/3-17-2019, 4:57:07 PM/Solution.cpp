// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>> ans;
        for(int i=0;i<strs.size();i++){
            string t = strs[i];
            sort(t.begin(),t.end());
            ans.push_back({strs[i],t});
        }
        vector<bool> check(ans.size(),0);
        vector<vector<string>> a;
        for(int i=0;i<ans.size();i++){
            vector<string> temp;
            if(check[i] == 0){
                check[i] = 1;
                temp.push_back(ans[i].first);
                for(int j=i+1;j<ans.size();j++){
                    if(check[j] == 0 && ans[j].second == ans[i].second){
                        check[j] =1;
                        temp.push_back(ans[j].first);
                    }
                }
                a.push_back(temp);
                temp.clear();
            }
        }
        return a;
    }
};