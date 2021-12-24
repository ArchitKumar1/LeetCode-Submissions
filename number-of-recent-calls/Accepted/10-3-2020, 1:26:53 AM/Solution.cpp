// https://leetcode.com/problems/number-of-recent-calls

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;


class RecentCounter {
public:
     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> X;
    int sz = 0;
    RecentCounter() {
        sz = 0;
    }
    
    int ping(int t) {
        X.insert(t);
        sz++;
        return sz - X.order_of_key(t-3000); 
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */