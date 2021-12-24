// https://leetcode.com/problems/minimum-interval-to-include-each-query

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
        vector<array<int,4>> v;
        int i =0;
        v.reserve(2*n);
        for(auto x : intervals){
            v.push_back({x[0],-1,x[1]-x[0]+1});
            v.push_back({x[1],1,x[1]-x[0]+1});
            i++;
        }
        sort(v.begin(),v.end());
        vector<array<int,2>> q;
        q.reserve(2*m);
        i =0;
        map<int,int> m1;
        for(auto x : queries){
            q.push_back({x, i});
            m1[x] = i;
            i++;
        }
        sort(q.begin(),q.end());
        
        vector<int> res(m,INT_MAX);
        
        int backans = 0;
        int backval = 0;
        
        
        multiset<int> range_min;
        
        int j = 0;
        for(auto x : v){
            int t = x[1];
            int v = x[0];
           // cout << x[0] << endl;
            int rangelen = x[2];
            
            while(j < m && q[j][0] < v && q[j][0] >= backval){
              //  cout << q[j][0] << " " << x[0] << " " << x[1] << " " << x[2] <<  " " << backans << endl;
                res[q[j][1]] = min(res[q[j][1]],backans);
                j++;
            }
            if(m1.find(v)!= m1.end()){
              //  cout << v << " E " << res[m1[v]] <<  " " << *range_min.begin() << endl;
                res[m1[v]] = min(res[m1[v]],*range_min.begin());
            }
            if(t == -1){
              //  cout << "Insert "<< x[0] << " " << x[1] << " " << x[2]  << endl;

                range_min.insert(rangelen);
            }else{
              //  cout << "Erase "<< x[0] << " " << x[1] << " " << x[2]  << endl;
                range_min.erase(range_min.find(rangelen));
            }
            // extra check 
            if(m1.find(v)!= m1.end()){
              //   cout << v << " E " << res[m1[v]] <<  " " << *range_min.begin() << endl;
                res[m1[v]] = min(res[m1[v]],*range_min.begin());
            }
            backans = *range_min.begin();
           //  cout << backans << " " << backval << endl;;
            backval = v;
        }
        for(int i = 0; i < m;i++){
            if(res[i] == 0) res[i] = -1;
        }
        return res;
    }
};