class Solution {
public:

    void change(vector<vector<int>> &image, int x, int y, int color, int src){
        int m = image.size(), n = image[0].size();
        if(x>=m || x<0 || y>=n || y<0 || image[x][y] == color || image[x][y] != src) return;

        image[x][y] = color;

        change(image, x+1, y, color, src);
        change(image, x-1, y, color, src);
        change(image, x, y+1, color, src);
        change(image, x, y-1, color, src);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        change(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};