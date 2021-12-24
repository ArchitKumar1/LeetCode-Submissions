// https://leetcode.com/problems/shuffle-an-array

class Solution {
public:
    vector<int> n ;
    vector<int> m;
    Solution(vector<int>& nums) {
        srand(chrono::high_resolution_clock::now().time_since_epoch().count());
        n = nums;
        m = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        m = n;
        return m;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(m.size() <= 1){
            return m;
        }
        A:
        int x = rand()%m.size();
        int y = rand()%m.size();
        if(x == y) goto A;
        
        swap(m[x],m[y]);
        return m;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */