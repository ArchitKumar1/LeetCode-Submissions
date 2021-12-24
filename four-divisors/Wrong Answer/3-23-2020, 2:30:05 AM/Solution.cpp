// https://leetcode.com/problems/four-divisors

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int c : nums){
            vector<int> f ;
            for(int i = 1;i*i<=c;i++){
                if(c%i == 0){
                    f.push_back(i);
                    if(c/i !=i)
                        f.push_back(c/i);
                }
            }
            if(f.size() ==4){
                int sum = 0;
                accumulate(f.begin(),f.end(),sum);
                ans += sum;
            }
            
        }
        return ans;
    }
};