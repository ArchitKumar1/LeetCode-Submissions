// https://leetcode.com/problems/minimum-speed-to-arrive-on-time

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        auto solve = [&](int speed) -> bool {
            double time = 0;
            int pos = 0;
            for(int d : dist){
                double timetaken = 1.0*d/speed;

                if(pos != dist.size()-1){
                    timetaken = ceil(timetaken);
                }
                time += timetaken;
                
                pos++;
            }
            return time <= hour;
        };
        int L = 0,H = 1e9;
        int ans = -1;
        while(L<=H){
            int M = (L+H)/2;
            if(solve(M)){
                H = M-1;
                ans = M;
            }else{
                L = M+1;
            }
        }
        return ans;
        
    }
};