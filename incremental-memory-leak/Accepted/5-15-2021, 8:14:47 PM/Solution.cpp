// https://leetcode.com/problems/incremental-memory-leak

class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        priority_queue<pair<int,int>> pq;
        pq.push({m1,2});
        pq.push({m2,1});
        vector<int> ans;
        for(int i = 1; i <= 400000;i++){
            pair<int,int>p = pq.top();
            pq.pop();
            if(p.first >= i){
                pq.push({p.first -i ,p.second});
            }else{
                pair<int,int>p2 = pq.top();
                ans = vector<int>(3);
                ans[0] = i;
                if(p.second == 2){
                    ans[1] = p.first;
                    ans[2] = p2.first;
                }else{
                    ans[2] = p.first;
                    ans[1] = p2.first;
                }
                break;
            }
        }
        return ans;
    }
};