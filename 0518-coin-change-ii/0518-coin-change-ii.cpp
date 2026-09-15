class Solution {
public:
    int helper (vector<int>&coins,int idx,int tar,vector<vector<int>>&dp){
        if (tar ==0) return 1;
        // As we are calculation the number of combinations here so we need to return them not the how many coins needed
        if(idx ==0){
            if (tar % coins[0]==0){
                return 1;
            }else{
                return 0;
            }
        }

        // We have the two conditions we can take the coin or not
        if (dp[idx][tar]!= -1) return dp[idx][tar];
        int not_take = helper(coins,idx-1,tar,dp);

        int take = 0;
        if (coins[idx]<=tar){
            take = helper(coins,idx,tar-coins[idx],dp);
        }
        return dp[idx][tar]=take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int m = amount;
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        int ans = helper (coins,n-1,amount,dp);
        return ans;
    }
};