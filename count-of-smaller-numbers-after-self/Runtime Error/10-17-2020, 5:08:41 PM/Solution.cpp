// https://leetcode.com/problems/count-of-smaller-numbers-after-self

class Solution {
public:
    
    class fen{
        public:
        vector<int> BIT;
        int N ;
        fen(int n){
            N = n+2;
            BIT.assign(N,0);
            
        }
        void add(int v,int i){
            while(i<N){
                BIT[i] += v;
                i+=(i&-i);
            }
        }
        int sum(int i){
            int ans =0 ;
            while(i>0){
                ans += BIT[i];
                i-=(i&-i);
            }
            return ans;
        }
    };
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        fen f(123456);
        
        for(int i = n-1;i>=0;i--){
            cout << nums[i] << endl;
            ans[i] = f.sum(nums[i] - 1);
            f.add(1,nums[i]);
        }
        return ans;
        
    }
};