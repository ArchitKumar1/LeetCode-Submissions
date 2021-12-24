// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts

class Solution {
public:
    int maxArea(int h, int w, vector<int>& H, vector<int>& W) {
        int mod = 1e9+7;
        vector<int> v1,v2;
        for(int i = 0;i+1<H.size();i++){
            v1.push_back(H[i+1]-H[i]);
        }
        for(int i = 0;i+1<W.size();i++){
            v2.push_back(W[i+1]-W[i]);
        }
        v1.push_back(H[0]);
        v1.push_back(h-H[H.size()-1]);
        
        v2.push_back(W[0]);
        v2.push_back(w-W[W.size()-1]);
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        map<int,int> m1,m2;
        
        for(int c :v1) m1[c]++;
        for(int c :v2) m2[c]++;
        
        long long int x = *max_element(v1.begin(),v1.end());
        long long int y = *max_element(v2.begin(),v2.end());
        
        int ans = x*y%mod * m1[x]*m2[y]%mod;
        return ans;
        
        
    }
};