// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans = 0;
        int l = 0;
        int h =100000;
        long long int sum = 0;
        
        while(l<=h){
            int mid = (l+h)/2;
            sum = 0;
            if(mid == 0)break;
            for(int i = 0;i<n;i++){
                
                sum += nums[i]/mid + (nums[i]%mid >0);
                cout << sum << endl;
            }
            cout << mid << " " << sum << endl;

            if(sum <=threshold){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};