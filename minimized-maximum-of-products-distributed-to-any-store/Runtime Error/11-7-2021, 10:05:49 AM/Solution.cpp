// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        
        
        int fans = -1;
        
        int l = 0;
        int h = 1e9;
        
        while(l <= h){
            int m = (l+h)/2;
            
            int nums = 0;
            for(int q : quantities){
                nums += (q / m);
                nums += (q % m > 0);
            }
            if(nums > n){
                l = m + 1;
            }else{
                fans = m;
                h = m - 1;
            }
        }
        return fans;
        
    }
};