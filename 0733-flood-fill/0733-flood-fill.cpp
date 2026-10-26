class Solution {
public:
    void f(vector<vector<int>>& image, int r, int c,int x, int color){
        int n = image.size();
        int m =image[0].size();
        if(r<0||r>=n||c<0||c>=m||image[r][c]!=x||image[r][c]==color)return ;
        image[r][c]=color;
        f(image,r-1,c,x,color);
        f(image,r+1,c,x,color);
        f(image,r,c-1,x,color);
        f(image,r,c+1,x,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        f(image,sr,sc,image[sr][sc],color);
        return image;
    }
};