class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        
        digits=[]
        while x>0:
            digit=x%10
            digits.append(digit)
            x=x//10
        
        n=len(digits)
        for i in range(0,n//2):
            if digits[i]!=digits[n-1-i]:
                return False
            
        return True