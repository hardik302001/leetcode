'''
Introducion :

If all digits sorted in descending order, then output is always -1. For example, 321.
For other cases, we need to process the number from rightmost side (why? because we need to find the smallest of all greater numbers)


Algorithm:

Traverse the given number from rightmost digit, keep traversing till you find a digit which is smaller than the previously traversed digit. For example, if the input number is “534976”, we stop at 4 because 4 is smaller than next digit 9. If we do not find such a digit, then output is “Not Possible”.

Now search the right side of above found digit ‘d’ for the smallest digit greater than ‘d’. For “534976″, the right side of 4 contains “976”. The smallest digit greater than 4 is 6.

Swap the above found two digits, we get 536974 in above example.

Now sort all digits from position next to ‘d’ to the end of number. The number that we get after sorting is the output. Finally, for above example, We get “536479” which is the next greater number for input 534976.

In last step we should check weather the result is a 32-bit number or not.

Code:
'''





class Solution:
    def nextGreaterElement(self, n):
        
        n=list(str(n))
        N=len(n)
        i = -1
        for x in range(N-1,0,-1):
            if n[x]>n[x-1]:
                i=x-1
                break
        if i==-1:  #if it is of form 987654321...i mean deecreaing..so it will never have next sameller permutuation..
            return -1
        
        swap=i  #current index
        pos=i   
        p = n[swap]  #current element
         
        for x in range(swap+1,N):
            if n[x]>p:              #start from next element of swap(cur index) and check for *next possible strictly greater element* bcz now array is in dec order 
                swap=x
            else:
                break
                
        
        n[pos],n[swap]=n[swap],n[pos]
        ans=int(''.join(n[:pos+1])+''.join(sorted(n[pos+1:])))
        
        return ans if len(bin(ans)[2:])<32 else -1