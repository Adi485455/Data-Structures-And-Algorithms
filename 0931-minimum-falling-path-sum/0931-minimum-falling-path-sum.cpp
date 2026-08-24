class Solution {
public:
    int helper(vector<vector<int>>&mat,vector<vector<int>>&dp,int i, int j){
        int n=mat.size();
        int m=mat[0].size();
        if(j<0 || j>=m) return 1e9;
        if(i==0) return mat[0][j];
       

        if(dp[i][j]!=1e9) return dp[i][j];

        int up = mat[i][j]+helper(mat,dp,i-1,j);
        int ld = mat[i][j]+helper(mat,dp,i-1,j-1);
        int rd =mat[i][j]+ helper(mat,dp,i-1,j+1);

        return dp[i][j]=min (up,min(ld,rd));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        int ans = 1e9;
        for(int j=0;j<m;j++){
            ans = min(ans,helper(matrix,dp,n-1,j));
        }
        return ans;
        
    }
};