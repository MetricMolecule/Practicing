class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        # binary search on answers
        # k is answer, range of k -> 1 to max
        def helper(k:int)->bool:
            total_hrs=0
            for x in piles:
                total_hrs+= (x+k-1)//k
            return total_hrs<=h

        lo=1
        hi=max(piles)
        ans=hi
        while lo<=hi:
            mid=lo+(hi-lo)//2

            if helper(mid)==True:
                ans=mid
                hi=mid-1
            else:
                lo=mid+1
        return ans
            
