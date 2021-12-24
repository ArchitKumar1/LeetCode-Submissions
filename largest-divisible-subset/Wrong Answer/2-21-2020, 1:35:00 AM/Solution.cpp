// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        map<long long int,int> m1;
        int n = nums.size();
        for(int c : nums){
            m1[c] = 1;
        }
        long long int limit = 2e9;
        int fans = 1;
        vector<int> vfans;
        for(int c :nums){
            int tans = 0;
            vector<int> vtans;
            if(c == 1 || c == 0) {
                tans = c;
                vtans = {c};
            }
            int p = 0;
            
            while(pow((long long)c,p)<=limit && c!= 1 && c!=0){
                // cout << c << " " << pow((long long)c,p) << endl;
                if(m1[pow((long long)c,p)] ==1){
                    tans++;
                    vtans.push_back(pow((long long)c,p)); 
                }
                p++;
            }

            if(tans> fans){
                fans = tans;
                vfans = vtans;
            }
        }
        sort(vfans.begin(),vfans.end());
        return vfans;
    }
};