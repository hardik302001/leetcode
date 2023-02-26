class Solution:
    def countElements(self, arr: List[int]) -> int:
        count = collections.Counter(arr)
        return sum(v for k, v in count.items() if count[k + 1])