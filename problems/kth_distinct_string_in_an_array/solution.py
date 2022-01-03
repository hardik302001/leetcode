class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        s = set()
        l = []
        for i in arr:
            if arr.count(i)==1:
                l.append(i)
        
        print(l)
        if len(l)>=k:
            return l[k-1]
        return ""
            