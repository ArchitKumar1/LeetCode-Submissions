// https://leetcode.com/problems/the-k-strongest-values-in-an-array

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        double med = 0.0;
        
        med = arr[(n-1)/2];
        
        sort(arr.begin(),arr.end(),[&](int a,int b){
            if(abs(1.0*a-med) !=abs(1.0*b-med)  ){
                return abs(1.0*a-med) > abs(1.0*b-med);
            }else{
                return a > b;
            }
        });
        vector<int> ans;
        for(int i= 0;i<k;i++){
            ans.push_back(arr[i]);
        }
        return ans;
        
    }
};