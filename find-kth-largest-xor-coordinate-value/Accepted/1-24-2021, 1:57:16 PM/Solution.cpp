// https://leetcode.com/problems/find-kth-largest-xor-coordinate-value

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        
        const int N = 1010;
        
        int Xor[N][N];
        memset(Xor,0,sizeof(Xor));
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> all;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                Xor[i][j] = matrix[i-1][j-1] ^ Xor[i-1][j] ^ Xor[i][j-1] ^ Xor[i-1][j-1];
                all.push_back(Xor[i][j]);
            }
        }
        sort(all.rbegin(),all.rend());
        return all[k-1];

    }
};