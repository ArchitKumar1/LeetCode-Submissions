// https://leetcode.com/problems/powerful-integers

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int>  ans;
        
        for(int k=0;k<=22;k++){
            for(int l=0;l<=22;l++){
                if(pow(x,k) +pow(y,l) <=bound)
                    ans.insert(pow(x,k) +pow(y,l));
            }
        }
         
        return vector<int>(ans.begin(),ans.end());
    }
};