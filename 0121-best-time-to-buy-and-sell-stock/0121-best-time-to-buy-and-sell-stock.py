class Solution:
    def maxProfit(self, a: List[int]) -> int:
        Min=a[0]
        prof=0
        for i in range(1,len(a)):
            cost=a[i]-Min
            prof=max(prof,cost)
            Min=min(Min,a[i])
        return prof