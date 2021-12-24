// https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list

class Solution {
public:
    
    
    vector<int> peopleIndexes(vector<vector<string>>& f) {
        unordered_map<string,int> m1[200];
        int pos = 0;
        for(auto x: f){
            for(auto y : x){
                m1[pos][y]++;
            }
            ++pos;
        }
        vector<int> ans;
        for(int i = 0;i<f.size();i++){
            bool ok = 1;
            for(int j = 0;j<f.size();j++){
                if(i== j)continue;
                bool safe = 1;
                for(auto x : m1[i]){
                    if(x.second >=1){
                        if(m1[j][x.first] == 0){
                            safe = 0;
                        }
                    }
                }
                if(safe == 1){
                    ok = 0;
                    break;
                }
                
            }
            if(!ok){
                ans.push_back(i);
            }
        }return ans;
        
        
    }
};