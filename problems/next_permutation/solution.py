#see question next greater element = iii

'''
logic is written in soln of that ques...


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
            n.sort()    #or n = n[::-1] bcz its already sorted in reverse direction
            return n
        
        swap=i  #current index
        pos=i   
        p = n[swap]  #currebt element
         
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
