class Solution:
    def convertToBase7(self, num: int) -> str:
        if not num:
            return "0"
        l=[]
        x=num
        if num<0:
            num=-num
        while num>0:
            r=num%7
            l.append(str(r))
            num//=7
        return "".join(l[::-1]) if x>=0 else "-"+ "".join(l[::-1]) 