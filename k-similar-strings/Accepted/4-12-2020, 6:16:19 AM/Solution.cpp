// https://leetcode.com/problems/k-similar-strings

class Solution {
public:
    int N;
    unordered_map<string,int> m1;
    string get(string a,string b){
        return a + '#' + b;
    }
    int solve(string a,string b){
        string maps = get(a,b);
        if(m1[maps] != 0){
            return m1[maps];
        }
        if(a == "" && b == "") return 0;
        if(a[0] == b[0]){
            return solve(a.substr(1),b.substr(1));
        }else{
            int ans = 1e9;
            for(int j = 1;j<a.size();j++){
                if(a[j] == b[0]){
                    string temp = a;
                    swap(temp[j],temp[0]);
                    ans = min(ans,1 + solve(temp.substr(1),b.substr(1)));
                }
            }
            return m1[maps] = ans;
        }
    }
    int kSimilarity(string A, string B) {
        N = A.size();
        return solve(A,B);
         
    }
};