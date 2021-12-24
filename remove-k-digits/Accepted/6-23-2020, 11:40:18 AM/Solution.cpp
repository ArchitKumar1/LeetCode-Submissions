// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = num;
        int fans ;
        
        while(k--){
            while(ans.size() && *ans.begin() == '0'){
                ans.erase(ans.begin());
            }
            if(ans == "") {
                fans = 0;
                break;
            }
            bool f = 0;
            for(int i =0;i+1<ans.size();i++){
                if(ans[i] > ans[i+1]){
                    f = 1;
                    ans.erase(ans.begin()+i);
                    i = ans.size();
                }
            }
            if(!f){
                ans.pop_back();
            }
        }
        while(ans.size() && *ans.begin() == '0'){
            ans.erase(ans.begin());
        }
        if(ans == "") return "0";
        return ans;
    }
};