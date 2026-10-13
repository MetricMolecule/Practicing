class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        " first we make an array of all the elements' squares & sort it"
        squares= sorted(x*x for x in nums)
        scores=0
        n=len(nums)
        for i in range(n):
            if i<n//2:
                scores-=squares[i]
            else:
                scores+=squares[i]
        
        return scores