// https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        string ans ;
        
        unordered_map<string,string> m1;
        for(auto v :knowledge ){
            m1[v[0]] = v[1];
        }
        
        int n = s.size();
        string curr;
        bool open = 0;
        
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                open = 1;
                curr = "";
            }
            
            if(open) curr += s[i];
            else ans += s[i];
            if(s[i] == ')'){
                if(m1.find(curr.substr(1,curr.size()-2))== m1.end()){
                    ans += "(?)";
                }else{
                    ans += m1[curr.substr(1,curr.size()-2)];
                }
                open = 0;
            }
        }
        return ans;
        
    }
};