// https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size(); 
        unordered_set<int> s[n];
        
        s[n-1] = {arr[n-1]};
        for(int i = n-2;~i;i--){
            s[i].insert(arr[i]);
            for(auto x : s[i+1]){
                s[i].insert(arr[i]&x);
            }
        }
        int ans = INT_MAX;
        
        for(int i =0;i <n;i++){
            for(auto x : s[i] ){
                ans = min(ans,abs(target-x));
            }
        }
        return ans;
        
    }
};