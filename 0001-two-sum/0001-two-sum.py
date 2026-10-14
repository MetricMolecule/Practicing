class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        indices={}
        n=len(nums)

        for i in range(0,n):
            indices[nums[i]]=i
        
        ans=[]

        for i in range(0,n):
            to_find=target-nums[i]
            if indices.get(to_find)!=None and indices.get(to_find)!=i:
                ans.append(i)
                ans.append(indices.get(to_find))
                break
        return ans