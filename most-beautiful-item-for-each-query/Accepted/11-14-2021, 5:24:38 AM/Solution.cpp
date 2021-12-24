// https://leetcode.com/problems/most-beautiful-item-for-each-query

#define ALL(x)    x.begin(),x.end()
#define LB        lower_bound
#define UB        upper_bound
#define PB        push_back
#define EB        emplace_back
#define F         first
#define S         second
#define endl      "\n"
#define SZ(x)     (int)x.size()


class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size();
        int m =  items.size();

        vector<int> ans(n);
        vector<int> idx(n);
        iota(ALL(idx),0);
        sort(ALL(items));
        sort(ALL(idx),[&](int a,int b){ return queries[a] < queries[b];});
        
        int j = 0;
        int mx = 0;
        for(int i : idx){
            while(j < m && items[j][0] <= queries[i]){
                mx = max(mx,items[j++][1]);
            }
            ans[i] = mx;
        }
        return ans;
    }
};