// https://leetcode.com/problems/happy-number

class Solution {
public:
    bool isHappy(int n) {
        
        int ans;
        map<int,int> m1;
        while(!m1[n]){
            
            m1[n] = 1;
            int temp = 0;
            while(n){
                temp += pow(n%10,2);
                n/=10;
            }
            cout << temp << endl;
            ans = temp;
            n = temp;
        }
        return (ans == 1);
    }
};