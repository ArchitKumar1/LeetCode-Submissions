// https://leetcode.com/problems/count-submatrices-with-all-ones

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int fans =0 ;
        int n = mat.size();
        int m = mat[0].size();
        
        
        
        for(int i = 0;i<n;i++){
            vector<bool> bit(m,1);
            for(int i2= i ;i2<n;i2++){
                
                for(int j = 0;j<m;j++){
                    if(mat[i2][j] == 0) bit[j] = 0;
                }
                for(int j = 0;j<m;j++){
                    int cnt = 0;
                    if(bit[j] == 1){
                        cnt = 1;
                        while(j+1<m && bit[j+1] == 1){
                            cnt +=1 ;
                            j++;
                        }
                    }
                    //cout << i << " " << i2 << " " << j << " " << cnt << endl;
                    fans += cnt*(cnt+1)/2;
                }
                
            }
            cout << endl;
        }
        return fans;
        
        
    }
};