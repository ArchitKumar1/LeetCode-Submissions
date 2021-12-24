// https://leetcode.com/problems/maximum-subarray-min-product

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int N = nums.size();
        int MOD = 1e9+7;
        vector<long long> sums(N+1);
        for(int i = 0; i < N;i++){
            sums[i+1] = sums[i] + nums[i];
           // sums[i+1] %= MOD;
        }
        
        vector<int> l(N),r(N);
        {stack<int> st;
            st.push(-1);

             for(int i = 0;i < N;i++){
                while(st.top()!= -1 && nums[st.top()] >= nums[i]){
                    st.pop();
                }
                l[i] = st.top()+1;
                st.push(i);
            }
        }
        {stack<int> st;
            st.push(N);
            
            for(int i = N-1;~i;i--){
                while(st.top()!= N && nums[st.top()] >= nums[i]){
                    st.pop();
                }
                r[i] = st.top()-1;
                st.push(i);
            }
        }
        long long ans = 0;
        for(int i = 0;i <N;i++){
            //cout << l[i]  << " " << r[i] << endl;
            int sumr = sums[r[i]+1];
            int suml = sums[l[i]];
            //cout << sumr << " SUM " << suml <<endl;
            ans = max(ans,nums[i]*1LL*(sumr -suml));
        }
        return ans % MOD;
    }
};