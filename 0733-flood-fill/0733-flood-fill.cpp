class Solution {
public:
    void f(vector<vector<int>>& image,vector<vector<int>>&vis, int r, int c,int x, int color){
        int n = image.size();
        int m =image[0].size();
        if(r<0||r>=n||c<0||c>=m||image[r][c]!=x||vis[r][c]==1)return ;
        image[r][c]=color;
        vis[r][c]=1;
        f(image,vis,r-1,c,x,color);
        f(image,vis,r+1,c,x,color);
        f(image,vis,r,c-1,x,color);
        f(image,vis,r,c+1,x,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m =image[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        f(image,vis,sr,sc,image[sr][sc],color);
        return image;
    }
};