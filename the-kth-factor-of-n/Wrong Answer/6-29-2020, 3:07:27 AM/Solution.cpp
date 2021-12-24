// https://leetcode.com/problems/the-kth-factor-of-n

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> cnt;
        for(int i = 1;i*i<=n;i++){
            if(n%i == 0){
                cnt.push_back(i);
                if(n/i != i) cnt.push_back(n/i);
            } 
        }
        sort(cnt.begin(),cnt.end());
        return cnt[k-1];
    }
};