// https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {

        auto check = [&](vector<char> &v ,string &w) -> bool{
            if(v.size()!= w.size()) return false;
            for(int i = 0;i < w.size();i++){
                if(v[i] == ' ') continue;
                if(v[i] != w[i]) return false;
            }
            return true;
        };
        bool fans = false;
        int n = board.size();
        int m = board[0].size();

        {for(int i = 0;i < n;i++){
            vector<char> v;
            for(int j = 0;j < m;j++){
                if(board[i][j] == '#'){
                    if(check(v,word))fans = true;
                    v.clear();
                }else{
                    v.push_back(board[i][j]);
                }
            }
            if(v.size() && check(v,word)) fans = true;
        }}
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m/2; j++) {
                swap(board[i][j],board[i][m-j-1]);
            }
        }
        {for(int i = 0;i < n;i++){
            vector<char> v;
            for(int j = 0;j < m;j++){
                if(board[i][j] == '#'){
                    if(check(v,word))fans = true;
                    v.clear();
                }else{
                    v.push_back(board[i][j]);
                }
            }
            if(v.size() && check(v,word)) fans = true;
        }}
        
        {for(int j = 0;j < m;j++){
            vector<char> v;
            for(int i = 0;i < m;i++){
                if(board[i][j] == '#'){
                    if(check(v,word))fans = true;
                    v.clear();
                }else{
                    v.push_back(board[i][j]);
                }
            }
            if(v.size() && check(v,word)) fans = true;
        }}
        for (int j = 0; j < m;j++) {
            for (int i = 0; i < n/2; i++) {
                swap(board[i][j],board[n-i-1][j]);
            }
        }
        {for(int j = 0;j < m;j++){
            vector<char> v;
            for(int i = 0;i < m;i++){
                if(board[i][j] == '#'){
                    if(check(v,word))fans = true;
                    v.clear();
                }else{
                    v.push_back(board[i][j]);
                }
            }
            if(v.size() && check(v,word)) fans = true;
        }}
        return fans;
    }
    
};