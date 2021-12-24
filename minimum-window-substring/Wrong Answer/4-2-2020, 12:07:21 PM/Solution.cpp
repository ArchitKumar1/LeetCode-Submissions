// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        string maxi(1e6,'0');
        int n = s.length();
        
        map <int,int> m1,curr;
        for(char c : t){
            m1[c-'A']++;
        }
        
        int i = 0 ;
        
        for(int j= 0 ;j<n;j++){
            
            curr[s[j]-'A']++;
            // cout << s.substr(i,j-i) << endl;
            while(curr[s[i]-'A']>m1[s[i]-'A']){
                curr[s[i]-'A']--;
                i++;
            }
            bool ok = 1;
            for(int k = 0;k<26;k++){
                ok&= curr[k]>=m1[k];
            }
            if(ok){
                string temp = s.substr(i,j-i+1) ;
                if(temp.size() < maxi.size() ){
                    maxi = temp;
                }
            }
            
        }
        return maxi;
    }
};