class Solution:
    def distributeCandies(self, candy: List[int]) -> int:
        s = set(candy)
        return min(len(s),len(candy)//2)