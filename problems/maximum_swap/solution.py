# O(n2)
# bute force 

# class Solution:
#     def maximumSwap(self, num: int) -> int:
#         num = str(num)
#         num = list(num)
#         n = len(num)
#         for i in range(n):
#             m = num[i]
#             ind = i
#             for j in range(i+1,n):
#                 if num[j]>=m:
#                     m = num[j]
#                     ind = j
#             # print(m,ind)
#             if m!=num[i]:
#                 num[i],num[ind] = num[ind],num[i]
#                 break
        
#         return int("".join(num))
    

class Solution:
    def maximumSwap(self, num: int) -> int:
        num = str(num)
        num = list(num)
        n = len(num)
        last = [-1]*10
        
        for i in range(n):
            last[ord(num[i]) - ord('0')] = i
        
        
        for i in range(n):
            for digit in range(9,int(num[i]),-1):
                if last[digit]>i:
                    num[i],num[last[digit]] = num[last[digit]],num[i]
                    return int("".join(num))
                
        
        return int("".join(num))