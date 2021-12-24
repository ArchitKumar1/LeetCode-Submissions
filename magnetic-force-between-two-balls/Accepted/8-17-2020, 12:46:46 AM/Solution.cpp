// https://leetcode.com/problems/magnetic-force-between-two-balls

class Solution {
public:
    
    bool solve(vector<int>& p, int m,int mid){
        int back = p[0];
        m--;
        for(int i = 1,j=1;i<p.size() && m;i++){
            if(p[i]-back >= mid){
                m--;
                back = p[i];
            }
        }
        return m==0;
    }
    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(),p.end());
        int l = 1;
        int r = 1e9;
        
        while(l<=r){
            int mid = (l+r)/2;
            if(solve(p,m,mid)){
                l = mid+1;
            }else{
                r =mid-1;
            }
        }
        return (l+r)/2;
    }
};