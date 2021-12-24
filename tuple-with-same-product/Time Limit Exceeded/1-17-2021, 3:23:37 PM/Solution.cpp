// https://leetcode.com/problems/tuple-with-same-product

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,vector<pair<int,int>>> m1;
        
        m1.reserve(1000001);
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int prod = nums[i] * nums[j];
                m1[prod].push_back({nums[i],nums[j]});
            }
        }
        int ans = 0;
        for(auto x : m1){
            int m = x.second.size();
            
            for(int i =0;i<m;i++){
                unordered_set<int> s;
                s.insert(x.second[i].first);
                s.insert(x.second[i].second);
                for(int j = i+1;j<m;j++){
                    if(s.find(x.second[j].first) != s.end()) continue;
                    if(s.find(x.second[j].second) != s.end()) continue;
                    ans += 8;
                }
            }
        }
        return ans;
    }
};