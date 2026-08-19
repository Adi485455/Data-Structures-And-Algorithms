class Solution {
public:

    /* The first approach we can think about is the obviously is the recursion approach.
    -> we have the 2-D grid here do there are two pointer's. SO if the any of them is out of bound then just return 0;
    Similary as we have the obstacle condition so if the i>=0 and j>=0 and we have [][]==1 so just gonna return the 0 again as its not a valid path.
    next condition if the we have the grid of size 1 only then just return that block way means only 1 way 
    and for other codition's we can go only down or right
    right = i,j-1
    down = i-1 ,j 
    the remaining to explore.
    */

    // Tabulation 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       
        for (int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if (i==0 && j==0 ) dp[i][j]=1;
                else{
                    int right =0 ,down =0;
                if (j>0) right = dp[i][j-1];
                if (i>0) down = dp[i-1][j];

                dp[i][j]=right+down;
            }
            }
        }
        return dp[n-1][m-1];
    }
};