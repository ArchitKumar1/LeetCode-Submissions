// https://leetcode.com/problems/kth-largest-element-in-a-stream

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

class KthLargest {
public:
    ordered_set<pair<int,int>> os;
    int pos = 0;
    int K = 0;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int c : nums){
            os.insert({c,pos++});
        }
    }
    
    int add(int val) {
        os.insert({val,pos++});
        return (*os.find_by_order(pos - K)).first;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */