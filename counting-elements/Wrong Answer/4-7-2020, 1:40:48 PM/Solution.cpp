// https://leetcode.com/problems/counting-elements

class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int,int> m1;
        for(int c : arr)m1[c]+=1;
        int ans= 0;
        for(auto x : m1){
            if(x.second >=1)
                ans += x.second * m1[x.first+1];
        }
        return ans;
    }
};