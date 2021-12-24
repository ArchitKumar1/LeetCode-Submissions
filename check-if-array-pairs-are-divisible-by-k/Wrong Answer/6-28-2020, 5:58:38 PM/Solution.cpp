// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cnt(k+1,0);
        for(int c :arr){
            cnt[(k + c%k)%k]++;
        }
        for(int x : cnt){
            cout << x << " ";
        }
        bool safe = 1;
        for(int i =1;i<=k/2;i++){
            safe&= cnt[i] == cnt[k-i];
        }
        if(k%2 == 0){
            safe&= cnt[k/2 + 1]%2 == 0;
        }
        return safe;
    }
};