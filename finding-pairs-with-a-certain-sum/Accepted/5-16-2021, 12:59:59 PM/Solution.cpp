// https://leetcode.com/problems/finding-pairs-with-a-certain-sum


class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    map<long long,int> m1;
    map<int,int> m2;
    map<int,int> cnt;
    
    
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
        for(int c : nums1){
            m1[c]++;
        }
        for(int c : nums2){
            m2[c]++;
        }
    }
    
    void add(int i, int val) {
        m2[nums2[i]]--;
        nums2[i]+=val;
        m2[nums2[i]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto [c,cnt] : m1){
            int rem = tot-c;
            ans += cnt * m2[rem];
        }
        return ans;
    }
    
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */