// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0)return 0;
        
      
        map<int,int> m1;
        set<int> s;
        for(int c : nums) m1[c]++,s.insert(c);
        
        bool ok = 1;
        while(s.size()){
            vector<int> temp ;
            for(int i = 0;i<k;i++){
                temp.push_back(*s.begin());
                s.erase(s.begin());
                
            }
            for(int i =1 ;i<k;i++){
                if(temp[i]-temp[i-1] != 1) {
                    ok = 0;
                    cout << "mila" << endl;
                    goto A;
                }
            }
            cout << temp.size() << endl;
            for(int i = 0;i<k;i++){
                cout << temp[i] << " ";
            }
            cout << endl;
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