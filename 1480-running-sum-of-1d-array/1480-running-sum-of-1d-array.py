class Solution:
    def runningSum(self, nums: list[int]) -> list[int]:
        ' other solution'
        'return list(accumulate(nums))'

        n=len(nums)
        for i in range(1,n):
            nums[i]=nums[i-1]+nums[i]
        
        return nums