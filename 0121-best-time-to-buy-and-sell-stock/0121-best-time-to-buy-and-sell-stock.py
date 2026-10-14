class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        n=len(prices)
        x=prices[0]
        profit=0
        for i in range(0,n):
            x=min(x,prices[i])
            profit=max(profit,prices[i]-x)
        return profit