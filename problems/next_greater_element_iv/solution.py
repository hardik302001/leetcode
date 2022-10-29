# idea : https://www.youtube.com/watch?v=vF7DkVJnfVQ

class Solution:
    def secondGreaterElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        nge1 = [-1]*n
        st = []
        
        for i in range(n):
            while len(st) and nums[i]>nums[st[-1]]:
                nge1[st[-1]] = i
                st.pop()
            st.append(i)
        
        nge2 = [-1]*n
        for i in range(n):
            l = nge1[i]
            if l==-1 or l>=n:
                nge2[i] = -1
                continue
            else:
                l = l + 1
            
            while l!=-1 and l<n and nums[i]>=nums[l]:
                l = nge1[l]
                
            if l==-1 or l>=n: nge2[i] = -1
            else            : nge2[i] = nums[l]
         
        return nge2
                
        