// https://leetcode.com/problems/maximum-score-from-removing-stones

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> v = {a,b,c};
        sort(v.begin(),v.end());
        int ans = 0;
        
        a = v[0],b=v[1],c=v[2];
        
        if(c > (a+b)){
            ans = a+b;
        }else{
            ans = (a+b+c)/2;
        }
        return ans;
    }
};