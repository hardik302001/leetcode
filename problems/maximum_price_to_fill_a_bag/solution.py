class Solution:
    def maxPrice(self, items: list[list[int]], capacity: int) -> float:
        score = 0
        ratio = lambda item: item[0] / item[1]
        for price, weight in sorted(items, key=ratio, reverse=True):
            take = min(weight, capacity)
            score += price * take / weight
            capacity -= take
        return -1 if capacity else score