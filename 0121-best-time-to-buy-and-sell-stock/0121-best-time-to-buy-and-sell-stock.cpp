class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Min=prices[0];
        int n=prices.size();
        int prof=0;
        for(int i=1;i<n;i++){
            int cost=prices[i]-Min;
            prof=max(prof,cost);
            Min=min(Min,prices[i]);
        }
        return prof;
    }
};