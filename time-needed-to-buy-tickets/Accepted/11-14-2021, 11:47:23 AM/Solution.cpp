// https://leetcode.com/problems/time-needed-to-buy-tickets

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        queue<pair<int,int>> q;
        int i = 0;
        
        for(int c :tickets){
            q.push(make_pair(c,i));
            i++;
        }
        while(q.size()){
            pair<int,int> c = q.front(); q.pop();
            ans++;
            --c.first;
            if(c.second == k && c.first == 0) return ans;
            if(c.first > 0) q.push(make_pair(c.first,c.second));
        }
        return -1;
    }
};