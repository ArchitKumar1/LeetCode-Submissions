// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        map<int,int>m1;
        for(int i =0;i<n;i++){
            m1[arr[i]]=1;
        }
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(m1[arr[i] + arr[j]] >= 1){
                    m1[arr[i] + arr[j]] = max(m1[arr[i] + arr[j]],m1[arr[j]]+1);
                }
            }
        }
        int ans = INT_MIN;
        for(auto x : m1){
            ans = max(ans,x.second);
        }
        return ans;
    }
};