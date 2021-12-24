// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
       int  back = 0;
        int n = arr.size();
        for(int i = 0; i < n;i++){
            if(arr[i] > back){
                back = back+1;
            }else if(arr[i] == back){
                continue;
            }else{
                assert(false);
            }
        }
        return back;
    }
};