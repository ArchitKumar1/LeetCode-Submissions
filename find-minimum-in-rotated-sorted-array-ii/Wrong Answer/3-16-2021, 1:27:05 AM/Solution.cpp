// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int l = 0;
        int h = n-1;
        
        int ans = -1;
        
        int MINI = *min_element(nums.begin(),nums.end());
        
        if(MINI == nums[0]){
            return nums[0];
        }
        while(l <= h){
            int m = (l+h)/2;
            
            int L = nums[l];
            int R = nums[h];
            int M = nums[m];
            
            if( M >= L ){
                //take right part;
                ans = m;
                l = m + 1;
            }else{
                
                h = m -1;
            }
        }
        cout << ans << endl;
        return nums[ans-1];
    }
};