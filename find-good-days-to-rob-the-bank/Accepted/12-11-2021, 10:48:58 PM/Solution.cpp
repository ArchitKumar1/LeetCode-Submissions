// https://leetcode.com/problems/find-good-days-to-rob-the-bank

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& sec, int time) {
        int n = sec.size();
        vector<int> ans;
        vector<int> left(n,1),right(n,1);
        for(int i = 1;i < n;i++){
            if(sec[i-1] >= sec[i]) left[i] = left[i-1] +1;
        }
        for(int i = n-2;i >= 0;i--){
            if(sec[i] <= sec[i+1]) right[i] = right[i+1] + 1;
        }
        for(int i = time;i+time< n;i++){
            if(left[i] >= (time+1) && right[i] >= (time+1)) ans.push_back(i);
        }
        cout << endl;
        
        return ans;
    }
};