class Solution {
    int count,m,n;
    vector<vector<int>>visited;
    void dfs(vector<vector<int>>& grid,int row,int col){
        visited[row][col] = 1;
        int a[4] = {-1, 0, 1, 0};
        int b[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newRow = row + a[i];
            int newCol = col + b[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m and grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
               dfs(grid,newRow,newCol);
            }else if(newRow<0 or newRow>=n or newCol<0 or newCol>=m or grid[newRow][newCol]==0 )count++;
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
         count=0;
         visited=vector<vector<int>>(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] and grid[i][j]==1){
                    dfs(grid,i,j);
                }
            }

        }
        return count;
    }
};