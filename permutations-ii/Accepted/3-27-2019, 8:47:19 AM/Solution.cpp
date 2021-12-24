// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> all_perm;
        do all_perm.push_back(nums); while (next_permutation(nums.begin(), nums.end()));
        return all_perm;
    }
};