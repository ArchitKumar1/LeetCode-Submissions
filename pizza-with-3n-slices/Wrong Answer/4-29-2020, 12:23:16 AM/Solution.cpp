// https://leetcode.com/problems/pizza-with-3n-slices

class Solution {
public:
    
    vector<int> sl;

    int get(int i,int j){
        // if(j-i <= 1){
        //     cout << i << " " << j << endl;
        //     cout << 0 << endl;
        //     return 0;
        // }
        if(j-i <= 2){
            cout << i << " " << j << endl;
            cout <<sl[i+1] << endl;
            return max({sl[i],sl[i+1],sl[i+2]});
            
        }
        int ans = max(sl[i+1] + get(i+3,j),sl[j-1] + get(i,j-3));
        ans = max(sl[i] + get(i+2,j-1),sl[j] + get(i+1,j-2));
        cout << i << " " << j << endl;
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
            int x = get(i,n-1+i) ;
            fans = max(fans,x);
        }
        // fans = get(0,n-1);
        return fans;
        
    }
};