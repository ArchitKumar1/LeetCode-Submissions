// https://leetcode.com/problems/number-of-different-integers-in-a-string

class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string>s;
        int n = word.size();
        
        for(int i= 0;i<n;i++){
            if(word[i] >='a'&& word[i] <='z')continue;
            int cnt = 1;
            int j = i;
            while(i+1 < n && word[i+1] >='0'&& word[i+1] <='9'){
                cnt++;
                i++;
            }
            string ans=  word.substr(j,cnt);
            while(ans.size() && *ans.begin()  == '0'){
                ans.erase(ans.begin());
            }
            s.insert(ans);
        }
        return s.size();
    }
};