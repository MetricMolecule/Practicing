class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        intervals.sort()
        n=len(intervals)
        a=intervals[0][0]
        b=intervals[0][1]
        ans=[]
        for i in range(1,n):
            x=intervals[i]
            c=x[0]
            d=x[1]
            if b<c:
                ans.append([a,b])
                a=c
                b=d
            else:
                b=max(b,d)

        ans.append([a,b])
        return ans