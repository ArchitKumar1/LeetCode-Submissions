// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<int,int> m1;
        vector<vector<int>> ind(26);
        for(int i = 0;i<S.size();i++){
            ind[S[i]-'a'].push_back(i);
        }
        
        vector<pair<int,pair<int,int>>> all;
        for(int i =0;i<26;i++){
            if(ind[i].size()){
                all.push_back({ind[i][0],{-1,i}});
                all.push_back({ind[i].back(),{1,i}});
            }
        }
        sort(all.begin(),all.end());
        
        vector<int> ans;
        int curr = 0;
        
        vector<int> cnt(26,0);
        
        auto check = [&](){
            for(int i =0;i<26;i++){
                if(cnt[i] > 0) return 0;
            }
            return 1;
        };
        
        for(auto x : all){
            auto[type ,val] = x.second;
            int i = x.first;
            if(type == -1){
                cnt[val] += 1;
            }else{
                cnt[val] -= 1;
            }
            if(check()){
                cout << i << endl;
               ans.push_back(i-curr+1);
                curr = i+1;
            }
            
        }
        return ans;
    }
};