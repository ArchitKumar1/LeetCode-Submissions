// https://leetcode.com/problems/delete-columns-to-make-sorted

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int m = A[0].size();
        int ans = 0;
        for(int j=0;j<m;j++)
        {
            int x = 0;
            for(int i=1;i<n;i++)
            {
                if(A[i][j] <A[i-1][j]){
                    x++;
                    i = n-1;
                }
            }
            if(x) ans++;
                
        }
        return ans;
    }
    
};