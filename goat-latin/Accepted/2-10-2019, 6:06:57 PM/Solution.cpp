// https://leetcode.com/problems/goat-latin

class Solution {
public:
    string toGoatLatin(string S) {
        vector<string> v;
        istringstream is( S );
        string word;
        while ( is >> word ) v.push_back( word );
        for(int i=0;i<v.size();i++){
            if(v[i][0]=='a'||v[i][0]=='e'||v[i][0]=='i'||v[i][0]=='o'||v[i][0]=='u' || v[i][0]=='A'||v[i][0]=='E'||v[i][0]=='I'||v[i][0]=='O'||v[i][0]=='U'){
                v[i].push_back('m');
                v[i].push_back('a');
               
            }
            else{
                char c=v[i][0];
                v[i].push_back(c);
                v[i].push_back('m');
                v[i].push_back('a');
                v[i].erase(0,1);
            }
            for(int j=0;j<i+1;j++)
                v[i].push_back('a');
        }
        string ans="";
        for(int i=0;i<v.size();i++){
            ans=ans+v[i];
            if(i!=v.size()-1) ans=ans+" ";
        }
        return ans;
            
    }
};