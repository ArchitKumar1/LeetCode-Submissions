// https://leetcode.com/problems/pizza-with-3n-slices

class Solution {
public:
    
    vector<int> sl;

    int get(int i,int j){
        if(j-i == 0)return 0;
        if(j-i == 2){
            return sl[i+1];
        }
        int ans = max(sl[i+1] + get(i+3,j),sl[j-1] + get(i,j-3));
        return ans;
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        for(int c : slices){
            sl.push_back(c);
        }
        for(int c : slices){
            sl.push_back(c);
        }
        
        int fans = 0;
        for(int i = 0;i<n;i++){
            fans = max(fans,get(i,i+n));
        }
        return fans;
        
    }
};