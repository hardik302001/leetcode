from collections import Counter
class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.a = nums1
        self.b = nums2
        self.d1 = Counter(self.a)
        self.d2 = Counter(self.b)
        # print(self.d1)
        # print(self.d2)
        

    def add(self, index: int, val: int) -> None:
        self.d2[self.b[index]]-=1
        self.b[index]+=val
        self.d2[self.b[index]]+=1
        # print(self.d2)
        
    def count(self, tot: int) -> int:
        c = 0
        for i in self.d1:
            if (tot - i) in self.d2 and self.d2[tot-i]>0:
                c += self.d1[i]*self.d2[tot - i]
        return c


# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)