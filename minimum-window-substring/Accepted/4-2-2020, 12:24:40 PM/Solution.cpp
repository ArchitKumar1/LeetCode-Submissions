// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        pair<int,int> ans = {-1,-1};
        int len = 1e7;
        int n = s.length();
        
        unordered_map <int,int> m1,curr;
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
            for(int k =(int)'A';k<=(int)'Z';k++){
                ok&= curr[k]>=m1[k];
            }
            for(int k =(int)'a';k<=(int)'z';k++){
                ok&= curr[k]>=m1[k];
            }
            if(ok){
                
                if(j-i+1 < len ){
                    len = j-i+1;
                    ans = {i,j};
                }
            }
            
        }
        if(ans == make_pair(-1,-1)){
            return "";
        }else{
            return s.substr(ans.first,ans.second-ans.first+1);
        }
    }
};