// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        map<int,set<int>> m1;
        for(auto x : adjacentPairs){
            m1[x[0]].insert(x[1]);
            m1[x[1]].insert(x[0]);
        }
        int st = 0;
        for(auto x : m1){
            if(x.second.size() == 1){
                st = x.first;
                break;
            }
        }
        int n = adjacentPairs.size() + 1;
        vector<int> ans(n);
        ans[0] = st;
        
        for(int i = 0;i<n-1;i++){
            int curr = ans[i];
            //add 
            set<int> s = m1[curr];
            auto nex = *s.begin();
            ans[i+1] = nex;
            
            
            // remove
            m1.erase(m1.find(curr));
            set<int> &t = m1[nex];
            t.erase(curr);
        }
        return ans;
        
    }
};