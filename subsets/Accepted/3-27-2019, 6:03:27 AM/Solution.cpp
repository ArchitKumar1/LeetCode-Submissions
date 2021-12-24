// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v1;
        int n  = nums.size();
        int a = pow(2,n);
        int cnt = 0;
        vector<int> temp;
        while(cnt!=a){
            temp.clear();
            
            for(int i=0;i<n;i++){
                if((1 << i) & cnt){
                    temp.push_back(nums[i]);
                }
                
            }
            //temp.resize(unique(temp.begin(),temp.end()) -temp.begin());
            v1.push_back(temp);
            cnt++;
        }
        //v1.resize(unique(v1.begin(),v1.end()) -v1.begin() );   
        return v1;
    }
};