// https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions

class Solution {
public:
    int minCharacters(string a, string b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        vector<int> f1(26),f2(26);
        for(int c : a) f1[c-'a']++;
        for(int c : b) f2[c-'a']++;
        
        int C = INT_MAX;
        
        for(int i = 1;i<26;i++){
            int curr = 0;
            for(int j =0;j<i;j++){
                curr += f2[j];
            }
            for(int j =i;j<26;j++){
                curr += f1[j];
            }
            C = min(C,curr);
        }
        for(int i = 1;i<26;i++){
            int curr = 0;
            for(int j =0;j<i;j++){
                curr += f1[j];
            }
            for(int j =i;j<26;j++){
                curr += f2[j];
            }
            C = min(C,curr);
        }
        vector<int> cnt(26,0);
        int total = a.size() + b.size();
        for(int c  : cnt){
            C = min(C,total - f1[c] - f2[c] );
        }
        return C;
    }
};