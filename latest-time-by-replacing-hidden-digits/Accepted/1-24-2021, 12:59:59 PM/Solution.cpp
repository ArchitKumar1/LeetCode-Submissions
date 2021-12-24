// https://leetcode.com/problems/latest-time-by-replacing-hidden-digits

class Solution {
public:
    string maximumTime(string time) {
        
        auto Make = [&](int x){
            string s = to_string(x);
            if(s.size() == 1) s = "0" + s;
            return s;
        };
        
        auto match = [&](char c , char t){
            return ((c == '?') || (c == t));
        };
        string fans;
        for(int H = 0;H<24;H++){
            for(int M = 0;M<60;M++){
                string h = Make(H);
                string m = Make(M);
                string curr = h + ":" + m;
                
                bool safe = 1;
                for(int i = 0;i<5;i++){
                    if(!match(time[i],curr[i])){
                       safe = 0; 
                    }
                }
                if(safe){
                    fans = curr;
                }
            }
        }
        return fans;
        
    }
};