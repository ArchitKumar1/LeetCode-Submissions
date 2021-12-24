// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        
        auto check = [&](vector<int> cnt1,vector<int> cnt2){
            bool ok = 1;
            for(int i =0 ;i<26;i++) ok&= cnt1[i] == cnt2[i];
            return ok;
        };
        vector<int> cnt1(26,0),cnt2(26,0);
        for(char c : p){
            cnt2[c- 'a']++;
        }
        int j = 0;
        for(int i = 0;i<n;i++){
            cnt1[s[i]-'a']++;
            if(i-j==m){
                cnt1[s[j]-'a']--;
                j++;
            }
            // for(int x =0 ;x<3;x++) {
            //     cout << i << " " << cnt1[x] << " " << cnt2[x] << endl;
            // }
            cout << endl;
            if(check(cnt1,cnt2)){
                ans.push_back(j);
            }
        }
        return ans;
    }
};