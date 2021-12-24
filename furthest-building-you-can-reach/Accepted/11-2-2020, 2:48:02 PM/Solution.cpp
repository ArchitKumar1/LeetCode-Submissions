// https://leetcode.com/problems/furthest-building-you-can-reach

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();
        
        
        auto safe = [&](int index){
            int B = bricks;
            int L = ladders;
            vector<int> costs;
            for(int i = 0;i+1<=index;i++){
                if(heights[i] < heights[i+1]){
                    costs.push_back(heights[i+1] - heights[i]);
                }
            }
            sort(costs.begin(),costs.end());
            bool safe = 1;
            for(int cost : costs){
                if(B >= cost){
                    B -= cost;
                }else if( L > 0){
                    L--;
                }else{
                    safe = 0;
                }
            }
            return safe;
        };
        
        int l = 0;
        int h = n-1;
        
        
        int ans = -1;
        
        while(l<=h){
            int m = (l+h)/2;
            if(safe(m)){
                ans = m;
                l = m+1 ;
            }else{
                h = m-1;
            }
        }
        return ans;   
    }
};