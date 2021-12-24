// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int len = 1e7;
        int n = s.length();
        
        map <int,int> m1,curr;
        for(char c : t){
            m1[c]++;
        }
        
        int i = 0 ;
        
        for(int j= 0 ;j<n;j++){
            
            curr[s[j]]++;
            // cout << s.substr(i,j-i) << endl;
            while(curr[s[i]]>m1[s[i]]){
                curr[s[i]]--;
                i++;
            }
            bool ok = 1;
            for(int k =0;k<256;k++){
                ok&= curr[k]>=m1[k];
            }
            if(ok){
                string temp = s.substr(i,j-i+1) ;
                if(temp.size() < len ){
                    len = temp.size();
                    ans = temp;
                }
            }
            
        }
        return ans;
    }
};