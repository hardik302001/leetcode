#see question next greater element = iii
# https://leetcode.com/problems/next-greater-element-iii/
# logic is written in soln of that ques...

'''
A bit of an explanation, with an example, just to help myself:

We start from the least significant digit, and traverse the bits. If each digit is larger than the last, there are no digits we can swap to achieve a greater number (return -1). Once we find a digit that we can swap (one that is smaller than the less significant digit before it), then we traverse to its right to find the least significant digit that is greater than it. Since we know that everything to the right of the first digit is in ascending order, the least significant digit is also the smallest digit. Thus, we swap out the first digit with the smallest digit that is also greater than it, guaranteeing that our new number will be greater. However, in order to get the smallest possible number, we still need to reverse the digits to the right, which were in ascending order, so that they will be in descending order, and thus smaller.

Example using 534976:
534976
534976
536974
  |  |
 now 536 is fixed and rest 3 places are variable  536_ _ _
 so to get the next smallest we need to sort( or reverse) the variable digits...
 
 
536479

'''

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
    def nextPermutation(self, n: List[int]) -> None:
        N = len(n)
        i = -1
        for x in range(N-1,0,-1):
            if n[x]>n[x-1]:
                i=x-1
                break
        if i==-1:
            n.sort()    # or n = n[::-1] bcz its already sorted in reverse direction
            return n
        
        swap=i  #current index
        pos=i   
        p = n[swap]  #current element
         
        for x in range(swap+1,N):
            if n[x]>p:              #start from next element of swap(cur index) and check for *next possible strictly greater element* bcz now array is in dec order 
                swap=x
            else:
                break
                
        print(pos, swap)
        n[pos],n[swap]=n[swap],n[pos]
        
        l, r = pos+1, N-1  # reverse the second part(or sort same thing bcz it already in decreasing)
        while l < r:
            n[l], n[r] = n[r], n[l]
           # print(n)
            l +=1 ; r -= 1
