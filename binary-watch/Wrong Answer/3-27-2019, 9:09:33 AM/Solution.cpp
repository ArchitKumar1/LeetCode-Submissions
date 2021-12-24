// https://leetcode.com/problems/binary-watch

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        int a = pow(2,10);
        int cnt = 0;
        vector<string> ans;
        while(cnt!=a){
            int x  = 0;
            for(int i=0;i<10;i++){
                if((1 << i) & cnt)
                    x++;
            }
            if(x == num){
                int a = 0;
                for(int i=0;i<6;i++){
                    if((1 << i) & cnt)
                        a += pow(2,i);
                }
                int b = 0;
                for(int i=6;i<10;i++){
                    if((1 << i) & cnt)
                        b += pow(2,i-6);
                }
                if(b>=60){
                    b = b-60;
                    a = a+1;
                }
                string p = to_string(a);
                string q = to_string(b);
                if(q.length() == 1)
                    q = '0' + q;
                string c = p+':'+q;
                ans.push_back(c);
            }
            cnt++;
        }
        return ans;
    }
};