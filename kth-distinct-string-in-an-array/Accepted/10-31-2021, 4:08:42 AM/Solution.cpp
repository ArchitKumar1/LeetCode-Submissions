// https://leetcode.com/problems/kth-distinct-string-in-an-array

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> m1;
        for(string s : arr ) m1[s]++;
        vector<string> brr;
        for(string s : arr ) if(m1[s] == 1) brr.push_back(s);
        if(brr.size() < k) return "";
        return brr[k-1];
    }
};