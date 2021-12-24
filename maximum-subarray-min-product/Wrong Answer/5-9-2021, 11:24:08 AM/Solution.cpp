// https://leetcode.com/problems/maximum-subarray-min-product

class Solution {
public:
    
    int maxSumMinProduct(vector<int>& nums) {
        int N = nums.size();
        int MOD = 1e9+7;
        vector<long long> sums(N+1);
        for(int i = 1; i <= N;i++){
            sums[i] = sums[i-1] + nums[i-1];
        }
        
        vector<int> l(N),r(N);
        {stack<int> st;
             for(int i = 0;i < N;i++){
                while(st.size() && nums[st.top()] >= nums[i]){
                    st.pop();
                }
                l[i] = st.size()==0 ? -1 : st.top();
                st.push(i);
            }
        }
        {stack<int> st;            
            for(int i = N-1;i>=0;i--){
                while(st.size() && nums[st.top()] >= nums[i]){
                    st.pop();
                }
                r[i] = st.size()==0 ? N: st.top();
                st.push(i);
            }
        }
        long long ans = 0;
        for(int i = 0;i <N;i++){
            cout << l[i] << " " << r[i] << endl;
            int sumr = sums[r[i]];
            int suml = sums[l[i]+1];
            ans = max(ans,nums[i]*1LL*(sumr -suml));
        }
        return (int)(ans % MOD);
    }
};