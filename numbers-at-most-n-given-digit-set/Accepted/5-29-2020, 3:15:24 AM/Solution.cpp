// https://leetcode.com/problems/numbers-at-most-n-given-digit-set

class Solution {
public:

    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int ans = 0;
        string n = to_string(N);
        int l = n.size();
        for(int i =1;i<l;i++){
            ans += pow(D.size(),i);
        }
        map<char,int> m1;
        for(string s : D){
            m1[s[0]]=1;
        }
        int d=0;
        for(;d<l;d++){
            for(int j = 1;j<=9;j++){
                if(j < (n[d]-'0') && m1['0'+j]){
                    ans += pow(D.size(),l-d-1);
                }
            }
            if(m1[n[d]] == 0 ){
                break;
            }
        }
        
        return ans + (d==l);
    }
};