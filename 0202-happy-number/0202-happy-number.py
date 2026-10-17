class Solution:
    def isHappy(self, n: int) -> bool:
        #recusursion helper function
        def squaresum(num:int)->int:
            total=0
            
            while num>0:
                digit=num%10
                total=total+(digit*digit)
                num=num//10
            return total
        
        seen=set()

        while n!=1 and n not in seen:
            seen.add(n)
            n=squaresum(n)
            
        return n==1