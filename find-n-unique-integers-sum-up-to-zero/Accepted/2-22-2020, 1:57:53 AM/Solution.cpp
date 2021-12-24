// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero

class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1) return vector<int>({0});
        int sum = n*(n-1)/2;
        vector<int> vec;
        vec.push_back(-sum);
        for(int i =0;i<n-1;i++){
            vec.push_back(i+1);
        }
        return vec;
    }
};