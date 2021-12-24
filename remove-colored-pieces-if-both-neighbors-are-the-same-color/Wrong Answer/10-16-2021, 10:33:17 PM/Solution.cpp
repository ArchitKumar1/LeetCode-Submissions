// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color

class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0,b = 0;
        int n = colors.size();
        for(int i = 0;i < n;i++){
            int cnt = 0;
            char c = colors[i];
            while(i+1<n && colors[i+1] == colors[i]) cnt++,i++;
            if(c == 'A') a += max(0,cnt-2);
            else b += max(0,cnt-2);
        }
        cout << a << " "<< b << endl;
        return a > b;
    }
};