// https://leetcode.com/problems/reverse-pairs

class Solution {
public:
    
    vector<int> nums;
    int n;
    long long ans = 0;
    
    void merge(int l,int mid,int r){
        
        for(int i = l, j = mid + 1;i <= mid;i++){
            while( j <= r && (long long) nums[i] > 2LL*nums[j]) j++;
            ans += j-mid-1;
        }
        
        int p = l ,q = mid + 1;
        vector<int> temp(r-l+1);
        int k = 0;
        
        while(p <= mid || q <= r){
            if(p <= mid && q <= r){
                if(nums[p] > nums[q]){
                    temp[k++] = nums[q++];
                }else{
                    temp[k++] = nums[p++];
                }
            }else if(p == mid+1){
                temp[k++] = nums[q++];
            }else{
                temp[k++] = nums[p++];
            }
        }
        k = r-l+1;
        for(int i = 0;i<k;i++){
            nums[l+i] =temp[i];
        }
    }
    void mergesort(int l,int r){
        if(l < r){
            int mid = (l+r)/2;
            mergesort(l,mid);
            mergesort(mid+1,r);
            merge(l,mid,r);
        }
    }
    int reversePairs(vector<int>& NUMS) {
        nums = NUMS;
        n = nums.size();
        
        mergesort(0,n-1);

        return ans;
                
    }
};