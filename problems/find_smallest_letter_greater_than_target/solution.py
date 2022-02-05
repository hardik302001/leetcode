# import bisect

# class Solution:
#     def nextGreatestLetter(self, letters: List[str], target: str) -> str:
#         ind = []
#         for i in letters:
#             ind.append(ord(i) - ord('a'))
#         tar = ord(target)- ord('a')
       
        
#         index =  bisect.bisect_left(ind, tar+1)  # why tar + 1?? bcz if I do tar, then it will consider indexes graeter than and equal to tar, but we dont want equal!! We only want greater than tar..so it can be greater than / equal to (tar + 1) 
        
#         if index==len(ind):
#             return chr(ind[0] + ord('a'))    # bcz it will circular , so tit will stop at the first element (index 0 ), bcz array is sorted in non decreasing order
#         else:
#             return chr(ind[index] + ord('a'))
    
    
    
    
    
    


class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        left = 0
        right = len(letters)-1
        
        while(left < right):
            mid = (left + right) // 2
            if letters[mid] > target:
                right = mid
            else:
                left = mid + 1
        if letters[left] <= target:   # bcz we always consider left!
            return letters[0]
        return letters[left]


