class Solution {
public:
    int helper(int idx1,int idx2,string &s1,string &s2,vector<vector<int>>&dp){
        if (idx1 == -1 || idx2 == -1 ) return 0;
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if (s1[idx1] == s2[idx2]){
            return dp[idx1][idx2]=1+helper(idx1-1,idx2-1,s1,s2,dp);
        }
        return dp[idx1][idx2]=max(helper(idx1-1,idx2,s1,s2,dp),helper(idx1,idx2-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return helper (n-1,m-1,text1,text2,dp);
    }
};