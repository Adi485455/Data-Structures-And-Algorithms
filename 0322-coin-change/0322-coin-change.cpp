class Solution {
public:
    int helper(vector<int>&coins,int idx,int amount,vector<vector<int>>&dp){

        //Base case as the question is to find the min so the we return the 1e9 so means the ans is not possible

        if (idx ==0) {
            if (amount % coins[0]==0){
                return amount /coins[0];
            }else{
                return 1e9;
            }
        } 

        // We add 0 here as the no coins taken so no number of coins added to ans
        if(dp[idx][amount] != -1) return dp[idx][amount]; 

        int not_take = 0 + helper(coins,idx-1,amount,dp);
        int take = 1e9;

        // Here in the take condition the main point is the as we have the choice to take single coin multiple times so we keep the idx as the same upto which the we required coins (means when the amount becomes > coins[idx] we move to the next iteam in the coins array)

        if(coins[idx] <= amount){
            take = 1+helper(coins,idx,amount-coins[idx],dp);
        }
        return dp[idx][amount]=min(not_take ,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        // So the first one is the memoisation approach / reccurance approach
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = helper(coins,n-1,amount,dp);

        if(ans >= 1e9){
            return -1;
        }else{
            return ans;
        }
    }
};