class Solution:
    def minimizeSet(self, divisor1: int, divisor2: int, a: int, b: int) -> int:
        l=1
        h=10**18
        ans = h
        p=lcm(divisor1,divisor2)
        
        def check(x):
            u1=a
            u2=b
            common = x//p                  # we cant use them anywhere
            limited1=(x//divisor2)-(x//p)  # if divisible by div2, then use it in arr1 
            limited2=(x//divisor1)-(x//p)  # if divisible by div1, then use it in arr2

            avail=x-common-limited1-limited2    # the remaining elements
            
            if limited1<u1:  # fill the remaining places using avail
                avail-= (u1-limited1)
            if limited2<u2:
                avail-= (u2-limited2)
            
            # if we arent left with remaining places, but we need them ,return False, else True
            if avail<0: return False
            else:       return True
                

        while l<h:
            mid=(l+h)//2
            if check(mid):
                ans=mid
                h=mid 
            else:
                l=mid+1
        return ans
    
