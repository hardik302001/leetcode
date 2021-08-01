class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        l = [a,b,c]
        l.sort()
        a = l[0]
        b = l[1]
        c = l[2]
        ans = a
        dif = c-b
        if a<=dif:
            c = c -a
        else:
            a = a -dif
            c = b
            if a%2==0:
                b = b - a//2
                c = c -a//2
                a = 0
            else:
                b = b - a//2 -1
                c = c - a//2
                a = 0
                
      
        print(a,b,c)
        ans = ans+ min(b,c)
        return ans
        