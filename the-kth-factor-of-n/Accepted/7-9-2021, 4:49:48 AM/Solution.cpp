// https://leetcode.com/problems/the-kth-factor-of-n

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> facts;
        
        for(int i = 1;i <= n;i++){
            if(n%i == 0)facts.push_back(i);
        }
        return  k > facts.size()? -1 : facts[k-1];
    }
};