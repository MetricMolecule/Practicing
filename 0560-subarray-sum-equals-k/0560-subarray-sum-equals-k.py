class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n=len(nums)
        prefix={0: 1}

        curr_sum=0
        counter=0
        'steps for prefix sum'
        for x in nums:
            'running sum'
            curr_sum+=x
            'count the frequency of matching earlier prefix sums'
            counter+=prefix.get(curr_sum-k,0)
            'record the current prefix sum to the dictionary'
            prefix[curr_sum] = prefix.get(curr_sum,0)+1
        
        return counter
