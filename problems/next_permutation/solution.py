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
            n.sort()
            return n
        
        swap=i+1
        pos=i
        
        for x in range(swap,N):
            if n[pos]<n[x]<=n[swap]:   #corner case handling
                swap=x
      #  print(pos, swap)
        n[pos],n[swap]=n[swap],n[pos]
    #    print(n)
        l, r = pos+1, N-1  # reverse the second part
        while l < r:
            n[l], n[r] = n[r], n[l]
           # print(n)
            l +=1 ; r -= 1
