// https://leetcode.com/problems/k-similar-strings

class Solution {
public:
    int N;
    unordered_map<string,int> m1;
    string get(string a,string b,int c){
        return a + '#' + b + '#' + to_string(c);
    }
    int solve(string a,string b,int i){
        string maps = get(a,b,i);
        if(m1[maps] != 0){
            return m1[maps];
        }
        if(i == N ) return 0;
        if(a[0] == b[0]){
            return solve(a.substr(1),b.substr(1),i+1);
        }else{
            int ans = 1e9;
            for(int j = i+1;j<N;j++){
                if(a[j] == b[i]){
                    string temp = a;
                    swap(temp[j],temp[i]);
                    ans = min(ans,1 + solve(temp.substr(i),b.substr(i),i+1));
                }
            }
            return m1[maps] = ans;
        }
    }
    int kSimilarity(string A, string B) {
        N = A.size();
        return solve(A,B,0);
         
    }
};