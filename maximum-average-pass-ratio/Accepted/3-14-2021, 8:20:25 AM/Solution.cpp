// https://leetcode.com/problems/maximum-average-pass-ratio

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        int n = classes.size();
        vector<double> pts(n);
        vector<int> passall(n);
        vector<int> totalall(n);
        
        priority_queue<pair<double,int>> pq;
        for(int i = 0;i<n;i++){
            vector<int> x = classes[i];
            
            int pass = passall[i] = x[0];
            int total = totalall[i] =  x[1];
            double curr = 1.0*pass/total;
            double newcurr = 1.0*(pass+1)/(total+1) - curr;
            pts[i] = curr;
            pq.push({newcurr,i});
        }
        while(extraStudents--){
            auto [curr,i] = pq.top(); pq.pop();
            pts[i] += curr;
            passall[i]++;
            totalall[i]++;
            double oldcurr = 1.0*(passall[i])/(totalall[i]);
            double newcurr = 1.0*(passall[i]+1)/(totalall[i]+1);
            pq.push({newcurr-oldcurr,i});
        }
        double ans = 0;
        for(int i = 0;i<n;i++){
            ans += pts[i];
        }
        return ans/n;
    }
};