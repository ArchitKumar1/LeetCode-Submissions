// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();
        if(n%k != 0)return 0;
        
        unordered_map<int,int> m1;
        set<int> s;
        for(int c : nums) m1[c]++,s.insert(c);
        
        bool ok = 1;
        while(s.size()){
            vector<int> temp ;
            for(int i = 0;i<k;i++){
                if(s.size()  >= 1){
                    temp.push_back(*s.begin());
                    s.erase(s.begin());
                }
                
            }
            if(temp.size() < k) {
                ok = 0;
                break;
            }
            for(int i =1 ;i<k;i++){
                if(temp[i]-temp[i-1] != 1) {
                    ok = 0;
                    goto A;
                }
            }
            for(int i = 0;i<k;i++){
                int curr = temp[i];
                m1[curr]--;
                if(m1[curr]>=1) s.insert(curr);
            }
        }
        A:
        return ok;
    }
};