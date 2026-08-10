class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        if (n==0) return 0;

        for(int i=n-1;i>=0;i--){
            
            for(int j=i-1;j>=-1;j--){
                int include =0;
                if(j == -1 || nums[i]>nums[j]){
                    include = 1+dp[i+1][i+1];
                }
                int exclude=dp[i+1][j+1];
                dp[i][j+1]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
};