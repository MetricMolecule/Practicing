class Solution {
public:
    void fill(vector<vector<int>>& image, int r, int c, int source, int color){
        int n=image.size();
        int m=image[0].size();
        if(r<0 || c<0 || c>m-1 || r>n-1) return;
        if(image[r][c]!=source) return;
        image[r][c]=color;
        fill(image,r-1,c,source,color);
        fill(image,r,c-1,source,color);
        fill(image,r+1,c,source,color);
        fill(image,r,c+1,source,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int source=image[sr][sc];
        //edgecase
        if(source==color) return image;
        fill(image,sr,sc,source,color);
        return image;
    }
};