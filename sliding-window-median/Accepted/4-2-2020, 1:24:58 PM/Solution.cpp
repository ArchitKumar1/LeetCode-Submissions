// https://leetcode.com/problems/sliding-window-median

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
//         priority_queue<int,vector<int>,greater<int>> pq2;
//         priority_queue<int> pq1;
        vector<double> ans;
        vector<int> curr;
        for(int i = 0;i<nums.size();i++){
            
            int pos = lower_bound(curr.begin(),curr.end(),nums[i]) - curr.begin();
            curr.insert(curr.begin()+pos,nums[i]);
            if(i >= k){
                
                int pos2 = lower_bound(curr.begin(),curr.end(),nums[i-k]) - curr.begin();
                // cout<<"DEBUG : "<< i << " " << nums[i-k] << " " << pos2 << endl;
                curr.erase(curr.begin()+pos2);
            }
            if(curr.size() == k){
                // for(int i = 0;i<k;i++){
                //     cout << curr[i] << " ";
                // }
                // cout << endl;
                double t = 0.0;
                if(curr.size()%2 == 0){
                    t += (long long int)curr[k/2] + curr[k/2 - 1];
                    t/=2;
                }else{
                    t += curr[k/2];
                }
                ans.push_back(t);
            }
        }
        return ans;
                  
    }
};