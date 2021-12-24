// https://leetcode.com/problems/minimum-absolute-difference

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        map<int,vector<vector<int>>> m1;
        
        sort(arr.begin(),arr.end());
        for(int i = 0;i+1<arr.size();i++){
            int diff = arr[i+1]-arr[i];
            m1[diff].push_back(vector<int>({arr[i],arr[i+1]}));
        }
        return m1.begin()->second;
        
    }
};