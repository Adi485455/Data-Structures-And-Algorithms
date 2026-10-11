
class Solution {
public:
    void helper_dfs(vector<vector<int>>& image,
                    int i, int j, int color,
                    int originalColor,
                    vector<vector<bool>>& vis) {

        int n = image.size();
        int m = image[0].size();

        // Invalid cell, visited cell, or different color
        if (i < 0 || j < 0 || i >= n || j >= m ||
            vis[i][j] || image[i][j] != originalColor) {
            return;
        }

        vis[i][j] = true;
        image[i][j] = color;

        // Up
        helper_dfs(image, i - 1, j, color, originalColor, vis);

        // Down
        helper_dfs(image, i + 1, j, color, originalColor, vis);

        // Left
        helper_dfs(image, i, j - 1, color, originalColor, vis);

        // Right
        helper_dfs(image, i, j + 1, color, originalColor, vis);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {
        if (image.empty() || image[0].empty()) return image;

        int originalColor = image[sr][sc];

        if (originalColor == color) return image;

        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        helper_dfs(image, sr, sc, color, originalColor, vis);

        return image;
    }
};
