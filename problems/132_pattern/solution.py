# TLE O(n3)

# class Solution:
#     def find132pattern(self, arr: List[int]) -> bool:
#         n = len(arr)
#         for i in range(n):
#             for j in range(n):
#                 for k in range(n):
#                     if i<j<k and arr[i]<arr[k]<arr[j]:
#                             return True
#         return False

# TLE O(n2)

# class Solution:
#     def find132pattern(self, arr: List[int]) -> bool:
#         n = len(arr)
#         mi = 1000000
#         for j in range(n):
#             for k in range(n):
#                 mi = min(arr[j] , mi)
#                 if j<k and mi<arr[k]<arr[j]:
#                     return True
#         return False

# O(n) , idea from NEETCODE VIDEO
# mi[st[-1]] for first element(1) , arr[st[-1]] for middle element(3) , and arr[k] for third element(2)
# minimise first as much as possible, maximise second as much as possible and traverse with third elmeent and check condition
# we consider that minimum value before that index uptill where we got the maximum middle element..i.e. mi[st[-1]], where st[-1] is index of maximum element before index k(third element) , TO MAINTAIN THE ORDER OF INDEX

class Solution:
    def find132pattern(self, arr: List[int]) -> bool:
        n = len(arr)
        mi = [arr[0]]
        for i in range(1, n):
            mi.append(min(mi[-1], arr[i]))
            
        
        st = []
        for k in range(1, n):

            while st and arr[st[-1]]<=arr[k]:     # nge type stack , we dont create nge array , we only consider elements in stack...
                st.pop()
         
            # now arr[st[-1]] will be maximum element (arr[j])   3
            # mi[st[-1]] will be minimum                         1
            # and arr[k] will be the third                       2
            
            if st and mi[st[-1]]<arr[st[-1]] and arr[st[-1]]>arr[k] and mi[st[-1]]<arr[k]:  # all 3 condition, 1<3 , 3>2 and 1<2
                print(mi[st[-1]] , arr[st[-1]], arr[k])
                return True
            
            st.append(k)    # now push current element
            
        return False
    
    
# 4th approach , you can also see code beyond video