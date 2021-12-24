// https://leetcode.com/problems/minimum-interval-to-include-each-query

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();        
        vector<int> order(m);
        
        iota(order.begin(),order.end(),0);
        sort(order.begin(),order.end(),[&](int &a, int &b){
            return queries[a] < queries[b];
        });
        vector<int> res(m);
             
        vector<array<int,3>> st,en;
        
        int i = 0 ;
        for(auto x : intervals){
            int len = x[1] - x[0] + 1;
            st.push_back({x[0],i,len});
            en.push_back({x[1],i,len});
            i++;
        }
        sort(st.begin(),st.end());
        sort(en.begin(),en.end());
        
        multiset<int> vals;
        int x = 0,y = 0;
        for(int i = 0 ; i < queries.size();i++){
            int q = queries[i];
            cout << q << endl;
            // Add startings
            while( x < n && st[x][0] <= q){
                cout << "insert " << x <<" "<< st[x][2]<< endl;
                vals.insert(st[x][2]);
                x++;
            }
            while( y < n && en[y][0] < q){
                cout << "remove " << y <<" "<< en[y][2]<< endl;
                vals.erase(vals.find(en[y][2]));
                y++;
            }
            res[order[i]] = (vals.size() > 0 ? *vals.begin() : -1);
            // Remove endings
            
        }
        
        return res;
    }
};