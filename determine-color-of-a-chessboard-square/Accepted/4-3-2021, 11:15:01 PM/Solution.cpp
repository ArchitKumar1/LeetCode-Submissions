// https://leetcode.com/problems/determine-color-of-a-chessboard-square

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int a = coordinates[0]-'a';
        int b = coordinates[1]-'1';
        
        return (a+b)&1;
    }
};