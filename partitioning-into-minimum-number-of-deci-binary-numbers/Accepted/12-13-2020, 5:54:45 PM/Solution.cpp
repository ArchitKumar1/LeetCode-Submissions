// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers

class Solution {
public:
    int minPartitions(string s) {
        char cm = '0';
        for(char c : s)
            cm = max(cm,c);
        return (int)(cm-'0');
    }
};