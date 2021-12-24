// https://leetcode.com/problems/plates-between-candles

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> cnts(n+1);
        for(int i = 0;i < n;i++){
            cnts[i+1] = (s[i] == '|') + cnts[i];
        }
        auto get = [&](int l,int r){
            return cnts[r+1] - cnts[l];
        };
        
        vector<int> v;
        for(int i = 0;i < n;i++){
            if(s[i] == '|') v.push_back(i);
        }
        int q = queries.size();
        vector<int> ans(q);
        
        for(int i = 0;i < q;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            auto il = lower_bound(v.begin(),v.end(),l);
            auto ir = upper_bound(v.begin(),v.end(),r);
            
            if(il == v.end() || *il > r) {
                // outside range
                ans[i] = 0;
            }else{
                ir = prev(ir);
                int L = *il;
                int R = *ir;
                cout << L << " " << R << " " << get(L,R) << endl;
                int count = R - L + 1 - get(L,R);
                ans[i] = count;
            }
        }
        return ans;
        
    }
};