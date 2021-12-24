// https://leetcode.com/problems/ways-to-make-a-fair-array

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
    
        vector<int> pref_odd(n+2,0),pref_even(n+2,0);
        
        for(int i = 1;i<=n;i++){
            pref_even[i] =pref_even[i-1];
            pref_odd[i] = pref_odd[i-1];
            if(i%2==1){
                    pref_even[i] += nums[i-1];
            }else{
                    pref_odd[i] += nums[i-1];
            }
            
            
        }
        int fans = 0;
        
        for(int i = 1;i<=n;i++){
            int le = pref_even[i-1];
            int lo = pref_odd[i-1];
            
            int re = pref_even[n] - pref_even[i];
            int ro = pref_odd[n] - pref_odd[i];
            
            
            //cout << le << " " << lo << " " << re << " " << ro << endl;
            
            fans += ((le+ro)==(re+lo));
        }
        return fans;
        
    }
};