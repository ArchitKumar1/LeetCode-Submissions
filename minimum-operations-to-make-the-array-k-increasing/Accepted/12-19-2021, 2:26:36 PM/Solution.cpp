// https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans = 0;
        vector<vector<int>> arrs(k);
        
        auto lcs = [&](vector<int>& nums){
            int n = nums.size();
            vector<int> vec;
            for(int c : nums){
                auto it = upper_bound(vec.begin(),vec.end(),c);
                if(it == vec.end()) vec.push_back(c);
                else{
                    int pos = it-vec.begin();
                    vec[pos] = c;
                }
            }
            return vec.size();
            
        };
        
        for(int i = 0;i < arr.size();i++){
            arrs[i%k].push_back(arr[i]);
        }
        for(auto v : arrs){
            ans += v.size() - lcs(v);
        }
        return ans;
    }
};