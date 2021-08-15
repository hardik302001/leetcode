'''
WE can make pairs, reduce the smaller ones to 1, and increase greater one to 2**p-2
see 2**p-1 will not make pair, bcz it have all 1

so we have 1 to (2**p-2)//2  and (2**p-2)//2 +1 to (2**p -2)
suppose p = 3

001
010
011

100
101
110


111

now 111 will not make pair with nayone.
lets take 110, so it will make pair with 001.. why?  bz its already (2**p-2)
wait here! lets mov ahead and you will get it soon!

next 101, so we will convert 101 to 110, we will use 010, after swapping on 2 and 3 posiyion we wll ahve 
110 and 001

next so same for 100 and 011, we will have 001 and 110


atleast we have 1 1 1 6 6 6 7
take product and do mod


'''




# p = 3
# 1 1 1 6 6 6 7

# 1**(2**p -2)//2    (2**p-2)**(2*p-2)//2     (2**p -1) 

class Solution:
    def minNonZeroProduct(self, p: int) -> int:
        x = 2**p -1     #last element
        z = pow((x-1),(x-1)//2,1000000007)    # half of elements are 2**p -2  , rest halfs are 1
        xx = pow(x,1,1000000007)
        return (xx*z)%1000000007