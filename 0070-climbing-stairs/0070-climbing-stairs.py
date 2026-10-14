class Solution:
    def climbStairs(self, n: int) -> int:
        # memo=[0]*n
        # memo[0]=1
        # memo[1]=2
        # if n==1 or n==2:
        #     return n
        # else:
        #     for i in range(2,n):
        #         memo[i]=memo[i-1]+memo[i-2]
            
        #     return memo[n-1]

        if n<=2:
            return n
        
        prev2=1
        prev1=2

        for i in range(3,n+1):
            current=prev1+prev2
            prev2=prev1
            prev1=current
        return prev1
