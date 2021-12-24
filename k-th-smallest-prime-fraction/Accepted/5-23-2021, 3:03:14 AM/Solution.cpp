// https://leetcode.com/problems/k-th-smallest-prime-fraction

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int N = arr.size();
        vector<pair<int,int>> v;
        for(int i = 0;i < N;i++){
            for(int j= i+1;j < N;j++){
                v.emplace_back(arr[i],arr[j]);
            }
        }
        sort(v.begin(),v.end(),[&](pair<int,int> &p1,pair<int,int> &p2){
            return  (p1.first * p2.second) < (p2.first * p1.second);
        });
        return vector<int>{v[k-1].first,v[k-1].second};
    }
};