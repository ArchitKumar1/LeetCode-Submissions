// https://leetcode.com/problems/maximum-repeating-substring

class Solution {
public:
    
    bool match(string a,string b){
        if(b.size() > a.size()) return 0;
        for(int i = 0;i<a.size();i++){
            if( i + b.size() <= a.size()){
                if(a.substr(i,(int)b.size()) == b){
                    return 1;
                }
            }else{
                break;
            }
        }
        return 0;
    }
    int maxRepeating(string sequence, string word) {
        
        int ans = 0;
        int T = 100;
        string base = "";
        for(int i = 1;i<=T;i++){
            base += word;
            if(match(sequence,base)){
                ans = i;
            }
        }
        return ans;
        
    }
};