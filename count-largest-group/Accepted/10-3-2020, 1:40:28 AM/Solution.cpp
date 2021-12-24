// https://leetcode.com/problems/count-largest-group

class Solution {
public:
    
    int countLargestGroup(int n) {
        
        auto get = [&](int x){
            int ans = 0;
            while(x){
                ans += x%10;x/=10;
            }
            return ans;
        };
        
        
        map<int,int> m1;
        for(int i = 1;i<=n;i++){
            m1[get(i)]++;
        }
        int ans = 0;
        int v = 0;
        
        map<int,int> m2;
        for(auto x : m1){
            
            m2[x.second]++;
        }
        for(auto x: m2){
            cout << x.first << " "<< x.second << endl;
            if(x.first >  v){
                v = x.first;
                ans = x.second;
            }
        }
        
        return ans;
        
    }
};