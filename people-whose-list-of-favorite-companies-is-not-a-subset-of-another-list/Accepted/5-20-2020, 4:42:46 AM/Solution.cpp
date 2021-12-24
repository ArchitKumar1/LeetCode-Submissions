// https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list

class Solution {
public:
    
    
    vector<int> peopleIndexes(vector<vector<string>>& f) {
        map<string,int> m1;
        int pos = 0;
        for(auto y : f){
            for(auto x : y){
                if(m1[x]){
                    continue;
                }else{
                    m1[x] = pos++;
                }
            }
        }
        vector<vector<int>> all;
        for(auto y : f){
            vector<int> cnt(pos+1,0);
            for(auto x: y){
                cnt[m1[x]]=1;
            }
            all.push_back(cnt);
            
        }
        vector<int> ans;
        int n = f.size();
        for(int i=0;i<n;i++){
            bool bad = 0;
            for(int j =0;j<n ;j++){
                if(i == j) continue;
                bool sub = 1;
                for(int k = 0;k<pos+1;k++){
                    sub&= (all[i][k]<=all[j][k]);
                }
                bad |= sub;
            }
            if(!bad){
                ans.push_back(i);
            }
        }
        return ans;
        
        
        
    }
};