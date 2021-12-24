// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous

class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> new_nums = nums;
        sort(new_nums.begin(),new_nums.end());
        new_nums.resize(unique(new_nums.begin(),new_nums.end()) - new_nums.begin());
        int duplicates = nums.size() - new_nums.size();
        
        vector<array<int,3>> segs;
        
        int n = new_nums.size();
        for(int i = 0;i < n;i++){
            int cnt = 1;
            int L = i;
            while( i + 1 < n && new_nums[i+1]- 1 == new_nums[i]){
                cnt += 1;
                i += 1;
            }
            segs.push_back({cnt,L,i});
        }
        sort(segs.begin(),segs.end());
        auto [cnt,L,R] = *segs.rbegin();
        // cout << cnt << " " << L << " " << R << endl;
        int ans = new_nums.size() - cnt + duplicates;
        return ans;
    }
};