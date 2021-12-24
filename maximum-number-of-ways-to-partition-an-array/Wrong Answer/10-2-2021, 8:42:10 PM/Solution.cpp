// https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array

template<class T>
void output_vector(vector<T> V){
    for(int i = 0; i < (int)(V.size());i++){
        if(i > 0) cout << " ";
        cout << V[i];
    }
    cout << '\n';
};

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> psums(n);
        psums[0] = nums[0];
        for(int i = 1;i < n;i++){
            psums[i] = nums[i] + psums[i-1];
        }
        map<int,int> m1;
        for(int i = 1;i<n;i++){
            m1[psums[i]]++;
        }
        int mans = 0;
        int mv = 0;
        for(auto [k,v] : m1){
            if( v > mv){  
                mv = v;
            }
        }
        return mv;
    }
};