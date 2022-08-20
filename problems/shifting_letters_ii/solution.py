
'''
It is a pretty simple range pref sum question.
After updating the ascii values from all shift operations, we will try to get our updated value within 'a' and 'z'.

One thing to note here is that we need to consider % 26, for having updated ascii value difference more than 26. I got 4 WA, bcz of that.

'''


class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        p = [0]*(n+1)
        
        # update from [ x: y ]
        for x, y, d in shifts:
            if d==0:
                p[x]-=1
                p[y+1]+=1
            else:
                p[x]+=1
                p[y+1]-=1
     
	 # take pref sum of range 
        for i in range(1 ,n):
            p[i]+=p[i-1]
            
            
        ans = ''
        for i in range(n):
            d = p[i] + ord(s[i])    # updated ascii value after operations
           
		   # but we want our value in between 'a' and 'z'
            if 97<=d and d<=122:   # if between 'a' and 'z' , then no issue
                pass
            elif d<97:   # if less than 'a', then we need to do relative shifting wrt to 'z'
                d = ord('z') - ( 96-d)%26
            elif d>122:    # if greater than 'z', then we need to do relative shifting wrt to 'a'
                d = (d-123)%26 + ord('a')  
            
            ans+= chr(d)      # convert to char
        return ans
		
		