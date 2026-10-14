class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        n=len(nums)
        total= 0
        for x in nums:
            total+=x
        
        ' my approach is to find the sum upto an index and subtract from total to get sum of other part after that index and then subtract and check if it is even'
        running_sum=0
        counter=0
        for i in range(0,n-1):
            running_sum+=nums[i]
            rem=total-running_sum
            if (running_sum-rem)%2==0:
                counter+=1
        
        return counter