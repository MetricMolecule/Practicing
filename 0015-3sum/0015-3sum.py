class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        n=len(nums)
        ans=[]
        # fix one element, check left and right, if sum zero append to ans list, else change left and right
        for i in range(0,n-2):
            if i>0 and nums[i-1]==nums[i]:
                continue
            # if a element is positive, every element after that will be +ve
            if nums[i]>0: 
                break
            left=i+1
            right=n-1

            while left<right:
                total=nums[i]+nums[left]+nums[right]

                if total==0:
                    ans.append([nums[i],nums[left],nums[right]])
                    left+=1
                    right-=1
                # if same, move once again
                    while left<right and nums[left]==nums[left-1]:
                        left+=1
                    while left<right and nums[right]==nums[right+1]:
                        right-=1
                
                elif total<0:
                    left+=1
                else:
                    right-=1
        
        return ans