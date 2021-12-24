// https://leetcode.com/problems/minimum-operations-to-make-a-subsequence

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {

        vector<int> a,d;
        unordered_map<int,int> m1;
        for(int c : target){
            m1[c] = m1.size()+1;
        }
        for(int c : arr){
            if(m1[c] > 0){
                a.push_back(m1[c]);
            }
        }
        for(int c : a){
            auto it = lower_bound(d.begin(),d.end(),c);
            if(it == d.end()){
                d.push_back(c);
            }else{
                *it = c;
            } 
        }
        return target.size()-d.size();
    }
};