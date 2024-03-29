class Solution(object):
    def findComplement(self, num):
        i = 1
        while i <= num:
            i = i << 1
        print(i)
        return (i - 1) ^ num
    
'''
The core is ^
111 ^ 101 = 010
Then the concern is to let the '0' in num complement to '1', because all the '1' in num will be complemented to "0" with ^.
So how to find the '0's in num
find another number that is one bit left than num and do minus 1.
e.g. 1000 (8) - 1 = 111 (7)
which will be the largest one in that bit-length, only having '1's.
With help of ^, '0' in num now will be complemented to '1'
'''