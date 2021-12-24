// https://leetcode.com/problems/camelcase-matching

class Solution {
public:
    vector<bool> camelMatch(vector<string>& q, string pattern) {
        int n = q.size();
        vector<bool> safe(n,0);
        for(int i = 0;i<n;i++){
            string s = q[i];
            string temp;
            for(char c : q[i]){
                if(c<='Z'){
                    temp+= c;
                }
            }
            cout << temp << " " << pattern << endl;
            if(temp == pattern){
                safe[i] = 1;
            }
        }
        return safe;
    }
};