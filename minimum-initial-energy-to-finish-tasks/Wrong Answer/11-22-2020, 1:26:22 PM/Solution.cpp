// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int fans = 0;
        priority_queue<pair<int,int>> pq;
        for(auto p : tasks){
            pq.push({p[0],p[1]});
        }
        
        int curr= 0;
        while(pq.size()){
            auto [req,mi] = pq.top();pq.pop();

            if(mi <= curr){
                curr -= req;
            }else{
                int diff = mi -curr;
                curr += diff;
                fans += diff;
                curr -= req;
            }
        }
        return fans;
    }
};