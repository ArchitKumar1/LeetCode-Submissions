// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    
    
    int minEatingSpeed(vector<int>& piles, int H) {
        
        
        auto can_eat = [&](int x){
            int ans = 0;
            for(int p : piles){
                ans += (p/x + (p%x > 0));
            }
            return ans <=H;
        };
        
        int l = 0;
        int h = 2e9;
        int ans = -1;
        while(l<=h){
            int mid = (l+h)/2;
            if(can_eat(mid)){
                cout << mid << endl;
                ans = mid;
                h = mid -1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};