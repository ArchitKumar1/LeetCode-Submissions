// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences

class Solution {
public:
    int maxProduct(string s) {
        int n = s.size();
        vector<int> p(1 << n);
        p[0] = 0;
        for(int m = 0;m < 1 << n;m++){
            vector<int> idx;
            idx.reserve(n);
            for(int j = 0;j < n;j++){
                if(m>>j&1) idx.push_back(j);
            }
            bool pali = true;
            for(int l = 0,r = idx.size()-1;l < r;l++,r--){
                if(s[idx[l]]!=s[idx[r]]) pali = false;
            }
            if(pali) p[m] = idx.size();
            //cout << bitset<5>(m) << " " << p[m] << endl;
        }
        for(int m = 0;m < 1 << n;m++){
            for(int j = 0;j < n;j++){
                if(m>>j&1){
                    int nm = m ^ (1 << j);
                    p[m] = max(p[m],p[nm]);
                }
            }
        }
        int fans = 0;
        for(int m = 0;m < 1 << n;m++){
            int xm = (-1 + (1 << n)) ^ (m);
            fans = max(fans,p[m] * p[xm]);
        }
        return fans;
        
    }
};