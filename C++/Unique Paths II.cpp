class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.empty())
        {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid.front().size();
        obstacleGrid[m - 1][n - 1] = !obstacleGrid[m - 1][n - 1];
        for (int i = m - 2; i >= 0; --i)
        {
            obstacleGrid[i][n - 1] = !obstacleGrid[i][n - 1]
                & obstacleGrid[i + 1][n - 1];
        }
        for (int i = n - 2; i >= 0; --i)
        {
            obstacleGrid[m - 1][i] = !obstacleGrid[m - 1][i]
                & obstacleGrid[m - 1][i + 1];
        }
        for (int i = m - 2; i >= 0; --i)
        {
            for (int j = n - 2; j >= 0; --j)
            {
                obstacleGrid[i][j] = obstacleGrid[i][j]
                    ? 0 : obstacleGrid[i + 1][j] + obstacleGrid[i][j + 1];
            }
        }
        return obstacleGrid[0][0];
    }
};
