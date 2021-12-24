// https://leetcode.com/problems/pizza-with-3n-slices

class Solution {
public:
    
    vector<int> sl;

    int get(int i,int j){
        if( j < i) return -1e9;
        if(j-i <= 2){
            int ans = 0;
            for(int x = i;x<=j;x++){
                ans = max(ans,sl[x]);
            }
            return ans;
            
        }
        int ans = max(sl[i+1] + get(i+3,j),sl[j-1] + get(i,j-3));
        ans = max(sl[i] + get(i+2,j-1),sl[j] + get(i+1,j-2));
        cout << ans << endl;
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
            int x = get(i,n+i-1) ;
            fans = max(fans,x);
        }
        // fans = get(0,n-1);
        return fans;
        
    }
};