// https://leetcode.com/problems/range-frequency-queries

class RangeFreqQuery {
public:
    vector<vector<int>> vs;
    RangeFreqQuery(vector<int>& arr) {
        int mx = *max_element(arr.begin(),arr.end());
        vs.resize(mx+2);
        int n  = arr.size();
        for(int i = 0;i < n;i++){
            vs[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        // cout << vs[value][0] << endl;
        if(vs[value].size() == 0) return 0;
        auto lo = lower_bound(vs[value].begin(),vs[value].end(),left) - vs[value].begin();
        auto up = upper_bound(vs[value].begin(),vs[value].end(),right) - vs[value].begin();
        // cout << lo << " " << up << endl;
        return (up - 1 +  lo+1);
        
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */