// https://leetcode.com/problems/arithmetic-subarrays

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int n =nums.size();
        int m = l.size();

        vector<bool> ans(m,0);
        
        for(int i = 0;i<m;i++){
            int L = l[i];
            int R = r[i];
            if(R-L<=1){
                ans[i] = 1;
            }else{
                set<int> diff;
                vector<int> v1(nums.begin()+L,nums.begin()+R+1);
                sort(v1.begin(),v1.end());
                for(int i = 1;i < (R-L+1);i++){
                    diff.insert(v1[i]-v1[i-1]);
                }
                cout << endl;
                ans[i] = (diff.size() == 1);
            }
            
        }
        return ans;
    }
};