// https://leetcode.com/problems/tuple-with-same-product

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        
        map<int,vector<pair<int,int>>> m1;
        
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
                for(int j = i+1;j<m;j++){
                    set<int> s;
                    s.insert(x.second[i].first);
                    s.insert(x.second[i].second);
                    s.insert(x.second[j].first);
                    s.insert(x.second[j].second);
                    if(s.size() == 4){
                        ans += 8;
                    }
                }
            }
        }
        return ans;
    }
};