class Solution:
    def reverse(self, x: int) -> int:
        rev=0
        flag=0
        if x<0:
            x=abs(x)
            flag=1
        while x!=0:
            pop=x%10
            x=x//10
        
            rev=rev*10+pop
        if rev>=-2**31 and rev<=2**31-1:
            if flag==1:
                return -rev
            else:
                return rev
        return 0