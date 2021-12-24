// https://leetcode.com/problems/making-file-names-unique

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        map<string,int> m1;
        vector<string> all;
        for(string s :names){
            if(m1[s] == 0){
                m1[s]+= 1;
                all.push_back(s);
            }else{
                int cnt = m1[s];
                all.push_back(s + '(' + to_string(cnt) +')');
                m1[s] +=1;
            }
        }
        return all;
    }
};