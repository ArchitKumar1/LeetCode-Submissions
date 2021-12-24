// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends

class Solution {
public:
    int minimumLength(string s) {
        list<pair<char,int>> L;
        
        int n = s.size();
        int ans = 0;
        for(int  i = 0;i<n;i++){
            int cnt = 1;
            while(i+1 < n && s[i+1] == s[i]){
                cnt++,i++;
            }
            L.push_back({s[i],cnt});
            ans += cnt;
        }
        while(L.size()){
            if(L.size() == 1){
                pair<char,int> p = *L.begin();
                if(p.second > 1) ans -= p.second;
                break;
            }else{
                pair<char,int> p1 = *L.begin();
                pair<char,int> p2 = *L.rbegin();
                if(p1.first == p2.first){
                    L.pop_front(),L.pop_back();
                    ans -= p1.second;
                    ans -= p2.second;
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};