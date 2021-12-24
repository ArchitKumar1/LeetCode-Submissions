// https://leetcode.com/problems/minimum-operations-to-make-a-subsequence

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {

        vector<int> a,d;
        map<int,int> m1;
        for(int c : target){
            m1[c] = m1.size()+1;
        }
        for(int c : arr){
            if(m1[c] > 0){
                a.push_back(m1[c]);
            }
        }
        for(int c : a){
            int C = m1[c];
            auto it = lower_bound(d.begin(),d.end(),C);
            if(it == d.end()){
                d.push_back(C);
            }else{
                *it = C;
            } 
        }
        return target.size()-d.size();
    }
};