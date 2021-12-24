// https://leetcode.com/problems/magnetic-force-between-two-balls

class Solution {
public:
    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(),p.end());
        int ans = INT_MAX;
        vector<int> all;
        int batch = (p.back() - p.front())/(m-1);
        for(int i = 0;i<m;i++){
            int l = p.front() + batch*i;
            cout << l << endl;
            auto val = lower_bound(p.begin(),p.end(),l);
            all.push_back(*val);
        }
        for(int i = 0;i+1<all.size();i++){
            ans = min(ans ,all[i+1] -all[i]);
        }
        for(int i = 0;i+1<all.size();i++){
            cout << all[i] << " ";
        }
        cout << endl;
        return ans;
    }
};