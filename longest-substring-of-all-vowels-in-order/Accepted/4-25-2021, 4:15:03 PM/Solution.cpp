// https://leetcode.com/problems/longest-substring-of-all-vowels-in-order

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans = 0;
        
        char back ;
        int len = 0;
        
        map<char,char> m1;
        m1['e'] = 'a';
        m1['i'] = 'e';
        m1['o'] = 'i';
        m1['u'] = 'o';
        
        int cnt = 0;
        for(char c : word ){
            //cout << len << " " << cnt <<  " " << back << endl;
            if(c == 'a'){
                if(back == 'a') len++;
                else{
                    len = 1;
                    cnt = 1;
                    back = 'a';
                }
            }else{
                if(back == m1[c]){
                    len++,cnt++;
                    back = c;
                }else if(back == c){
                    len++;
                }else{
                    len = 0;
                    cnt = 0;
                    back = c;
                    
                }
                if(cnt == 5){
                    ans = max(len,ans);
                }
            }
            //cout << len << " " << cnt <<  " " << back << endl;

        }
        return ans;
    }
};