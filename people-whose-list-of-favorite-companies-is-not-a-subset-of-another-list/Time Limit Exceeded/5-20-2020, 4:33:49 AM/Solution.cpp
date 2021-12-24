// https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list

class Solution {
public:
    
    
    vector<int> peopleIndexes(vector<vector<string>>& f) {
        map<string,int> m1[200];
        int pos = 0;
        for(auto x: f){
            for(auto y : x){
                m1[pos][y]++;
            }
            ++pos;
        }
        vector<int> ans;
        for(int i = 0;i<f.size();i++){
            bool ok = 0;
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
                ok |=safe;
            }
            if(!ok){
                ans.push_back(i);
            }
        }return ans;
        
        
    }
};