// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)     {
        int initcol=image[sr][sc];
        if(initcol==newColor) return image;
        image[sr][sc]=newColor;
        int h=image.size(); int w=image[0].size();
        int x[4]={1,-1,0,0}; int y[4]={0,0,1,-1};
        for(int i=0;i<4;i++){
            if(!(sr+x[i]<0 || sr+x[i]>=h || sc+y[i]<0 || sc+y[i]>=w) && image[sr+x[i]][sc+y[i]]==initcol){
                floodFill(image,sr+x[i],sc+y[i],newColor);
            }
        }
        return image;
    }
    
};