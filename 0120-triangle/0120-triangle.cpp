class Solution {
public:

    /*
    1 -> RECURRANCE :- 
     The approach would be the recurance approach.So means let's say we're going from the bottom-most element to top as we usually do int the recurance so we dont have the starting point as we can see here ther are the multiple ending points here where we can land.we don't have any particular ending point in the last row where can reach so bottom-up approach not gonna work.
     Base case here is the if we reach the end of the row means at (i-1) we can't go further down so just return whats we have a[i-1][j]
     So need to go by top-down approach.So we started from the point so we have two choices we can move to the direct down (↓) or can move diagonally (⟍) so means 
     down = (i+1,j) 
     diagonal = (i+1,j+1)
     and we must need to add the current value to the solution
     d = f(i+1,j)+a[i][j];
     di= f(i+1,j+1)+a[i][j];
     so the min value is min(d,di);

     2 -> Memoization :- 
     We first need to see the overlapping sub-problems 
     lets say we go 2-3-6-1 so in second way we go 2-3-5-1 so we've calculated the f call for the 2 ,3 ,1 two times so overlapping subproblems exists;


    */

   // Memoisation Solution

    // int helper(int i,int j,int n,vector<vector<int>>&dp,vector<vector<int>>& triangle){

    //     if(i==n-1) return triangle[n-1][j];
    //     if(dp[i][j]!= -1) return dp[i][j];

    //     int d = triangle[i][j]+helper(i+1,j,n,dp,triangle);
    //     int di = triangle[i][j]+helper(i+1,j+1,n,dp,triangle);

    //     return dp[i][j]=min(d,di);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
      
        int n=triangle.size();
        int m = triangle[0].size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int j =0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i = n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d = triangle[i][j]+dp[i+1][j];
                int di = triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(d,di);
            }
        }
        //return helper(0,0,n,dp,triangle);
        return dp[0][0];
    }
};