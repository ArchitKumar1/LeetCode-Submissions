// https://leetcode.com/problems/relative-sort-array

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> m1;
        int pos = 0;
        for(int c : arr2)m1[c] = ++pos;
        
        sort(arr1.begin(),arr1.end(),[&](int a,int b){
            if(m1[a] != 0 && m1[b]!=0){
                return m1[a] < m1[b];
            }if(m1[a] == 0 && m1[b] == 0){
                return a < b;
            }else{
                if(m1[a]){
                    return true;
                }else{
                    return false;
                }
            }
        });
        return arr1;
    }
};