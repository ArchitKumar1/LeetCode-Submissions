// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> m1;
        for(int c : nums)m1[c]++;
        
        
        int fans = 0;
        set<int> s;
        for(int c : nums) s.insert(c);
        for(auto x : s){
            if(k == 0){
                if(m1[x] > 1){
                    fans += 1;
                }
            }else{
                if(m1[x+k]>0){
                    fans += 1;
                }
            }
        }
        return fans;
    }
};