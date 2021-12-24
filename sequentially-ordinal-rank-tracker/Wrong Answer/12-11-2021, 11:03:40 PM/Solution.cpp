// https://leetcode.com/problems/sequentially-ordinal-rank-tracker

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

class SORTracker {
public:
    int cnt = 0;
    ordered_set<pair<int,string>> os;
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        os.insert({score,name});
    }
    
    string get() {
        return os.find_by_order(cnt++)->second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */