// https://leetcode.com/problems/maximum-product-of-word-lengths

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        unordered_map<int,int> m1;
        for(string s : words){
            int x = 0;
            for(char c : s){
                x |= (1 << (c-'a'));
            }
            m1[x] = max(m1[x],(int)s.size());
        }
        unordered_map<int,int> m2 = m1;
        int ans = 0;
        for(auto x : m1){
            for(auto y : m2){
                if(x.first == y.first) continue;
                if((x.first & y.first) ==0){
                    ans = max(ans,x.second * y.second);
                }
            }
        }
        return ans;
        
    }
};