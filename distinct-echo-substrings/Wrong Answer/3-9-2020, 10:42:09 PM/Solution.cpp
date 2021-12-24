// https://leetcode.com/problems/distinct-echo-substrings

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_map<string,int> m1;
        int n = text.size();
        int ans = 0;
        for(int l = 2;l<n;l++){
            for(int i = 0;i+l<n;i++){
                if(l%2 == 0){
                    string s = text.substr(i,l);
                    string t = text.substr(i,l/2);
                    if(s == (t+t)){
                        cout << s << endl;
                        if(m1.find(s) == m1.end()){
                            ans += 1;
                            m1[s] = 1;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};