// https://leetcode.com/problems/create-sorted-array-through-instructions

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        long long ans = 0;
        ordered_set<pair<long long,long long>> os;
        map<long long,int> m1;
        
        int cnt = 0;
        for(int c : instructions){
            long long l = os.order_of_key({c,0});
            long long r = cnt - os.order_of_key({c,m1[c]+10});
            cnt += 1;
            ans += min(l,r);
            os.insert({c,m1[c]++});
        }
        return ans;
    }
};