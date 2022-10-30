# start from back 
# consider digital root, 
# current digit to c*(next power of 10) , where c is (next + 1), where next is (i+1)th index digit, where i is curent index
# when all digits are exhausted, it will be 1*(next power of 10)

class Solution:
    def makeIntegerBeautiful(self, n: int, target: int) -> int:
        
        nn = n
        def dig(n):
            c = 0
            while n>0:
                c+=n%10
                n = n//10
            return c
        
        p = 10
        ans = 0
        while dig(n)>target:
            last = n%p
            dif = p - last
            ans +=dif
            n = n + dif
            p = p * 10
        return ans
    
    
'''

467
7 = dif = 3
470 
dif = 30

500
1000 


93274970 % 100




'''