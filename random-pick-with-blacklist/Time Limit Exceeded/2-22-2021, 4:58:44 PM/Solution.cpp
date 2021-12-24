// https://leetcode.com/problems/random-pick-with-blacklist

class Solution {
public:
    unordered_set<int> ump;
    int N;
    Solution(int n, vector<int>& blacklist) {
        for(int c : blacklist) ump.insert(c);
        N = n;
    }
    
    int pick() {
        int ans = -1;
        
        do{
            ans = rand()%N;
        }while(ump.find(ans)!=ump.end());
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */