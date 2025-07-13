class Solution {
    int n, m;
    vector<vector<char>> grid;
    vector<vector<int>> visited;

    void dfs(int row, int col) {
        visited[row][col] = 1;
        int a[4] = {-1, 0, 1, 0};
        int b[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newRow = row + a[i];
            int newCol = col + b[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                if (grid[newRow][newCol] == '1' && !visited[newRow][newCol]) {
                    dfs(newRow, newCol);
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        grid = matrix;
        visited = vector<vector<int>>(n, vector<int>(m, 0));

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j);
                    result++;
                }
            }
        }
        return result;
    }
};
