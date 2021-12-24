// https://leetcode.com/problems/delete-columns-to-make-sorted

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int m = A[0].size();
        int ans = 0;
        for(int j=0;j<m;j++)
        {
            string temp ="";
            for(int i=0;i<n;i++)
            {
                temp+=A[i][j];
            }
            string a = temp;
            int x = 0;
            for(int i=1;i<n;i++){
                if(temp[i] >= temp[i-1])
                    continue;
                x++;
            }
            if(x)
                ans++;
        }
        return ans;
    }
    
};