// https://leetcode.com/problems/bitwise-ors-of-subarrays

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> all;
        
        set<int> running;
        for(int c : A){
            set<int> temp;
            temp.insert(c);
            for(int x : running){
                temp.insert(x|c);
            }
            for(int x : temp){
                all.insert(x);
                running.insert(x);
            }
        }
        return all.size();    }
};