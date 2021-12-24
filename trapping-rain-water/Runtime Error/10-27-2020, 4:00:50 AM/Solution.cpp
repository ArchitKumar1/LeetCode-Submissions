// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> l(n,0),r(n,0);
        l[0] = h.front();
        r[n-1] = h.back();
        int fans = 0;
        for(int i =1;i<n;i++){
            l[i] = max(l[i-1],h[i]);
        }
        for(int i =n-2;i>=0;i--){
            r[i] = max(r[i+1],h[i]);
        }
        for(int i = 0;i<n;i++){
            fans += max(min(l[i],r[i])-h[i],0);
        }
        return fans;
        
    }
};