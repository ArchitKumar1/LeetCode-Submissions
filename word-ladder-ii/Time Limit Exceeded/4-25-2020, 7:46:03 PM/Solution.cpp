// https://leetcode.com/problems/word-ladder-ii

class Solution {
public:
    
    struct s{
        vector<string> s;
    };
    map<string,int> m1,m2;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
         vector<vector<string>> ans;
        
        for(string s : wordList){
            m1[s] +=1;
        }
        
        queue<s>qq;
        qq.push({vector<string>({beginWord})});
        
        while(qq.size()){
            s temp = qq.front();
            qq.pop();
            
            string curr = temp.s.back();
            if(m2[curr] == 1) continue;
            if(curr == endWord ){
                ans.push_back(temp.s);
            }
            for(int i = 0;i<curr.size();i++){
                for(int j = 1;j<=25;j++){
                    string t = curr;
                    t[i] = 'a' + (t[i] - 'a' + j)%26;
                    s newtemp = temp;
                    cout <<  t << endl;
                    if(m1[t] == 1){
                        newtemp.s.push_back(t);
                        qq.push(newtemp);
                    }
                }
            }
        }
        return ans;
    }
};