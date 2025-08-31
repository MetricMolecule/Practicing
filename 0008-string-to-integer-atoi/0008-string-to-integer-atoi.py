class Solution:
    def myAtoi(self, s: str) -> int:
        def helper(i, val, sign, started):
            if i>=len(s):
                return val*sign

            c=s[i]
            if not started and c==" ":
                return helper(i+1,val, sign, False)
            if not started and c in "+-":
                return helper(i+1,val,-1 if c=="-" else 1, True)
            if c.isdigit():
                val = val*10+ int(c)
                if sign==1 and val>= 2**31- 1:
                    return 2**31-1
                if sign ==-1 and -val<= -2**31:
                    return -2**31
                return helper(i+1,val,sign, True)
            return val*sign
        return helper(0,0,1,False) 