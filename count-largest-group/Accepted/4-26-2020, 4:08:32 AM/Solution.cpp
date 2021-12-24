// https://leetcode.com/problems/count-largest-group

class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int> m1;
        for(int i = 1;i<=n;i++){
            int y = i;
            int sum = 0;
            while(y){
                sum += y%10;
                y/=10;
            }
            m1[sum]++;
        }
        int ans = 0;
        for(auto c : m1){
            ans = max(ans,c.second);
        }
        int fans =0 ;
        for(auto c : m1){
            if(c.second == ans){
                fans += 1;
            }
        }
        return fans;
    }
};