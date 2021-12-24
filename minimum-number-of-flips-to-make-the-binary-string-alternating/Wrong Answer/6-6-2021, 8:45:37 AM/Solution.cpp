// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating

class Solution {
public:
    int minFlips(string s) {
        pair<int,int> ones;
        pair<int,int> zs;
            
        int n = s.size();
        
        for(int i = 0; i < n;i++){
            if(i %2 == 0){
                if(s[i] == '1'){
                    ones.second++;
                }else{
                    zs.second++;
                }
            }else{
                if(s[i] == '1'){
                    ones.first++;
                }else{
                    zs.first++;
                }
            }
        }
        int ans = INT_MAX;
        
        for(int i = 0; i < n;i++){
            if(s[i] == '1'){
                ones.second--;
                if(n&1){
                    ones.second++;
                }else{
                    ones.first++;
                }

            }else{
                zs.second--;
                if(n&1){
                    zs.second++;
                }else{
                    zs.first++;
                }
            }
            swap(ones.first,ones.second);
            swap(zs.first,zs.second);
            //assume even 1 odd 0
            {
                int a1 = ones.first + zs.second;
                int a2 = ones.second + zs.first;
                
                ans = min(ans,min(a1,a2));
            }
                
            
        }
        return ans;
    }
};