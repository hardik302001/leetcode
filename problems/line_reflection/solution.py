class Solution:
    def isReflected(self, points: List[List[int]]) -> bool:
        p = set(map(tuple, points))
        minx, _ = min(points, key=lambda x: x[0])
        maxx, _ = max(points, key=lambda x: x[0])
        rx = (minx + maxx) / 2
        return all((rx - (x-rx), y) in p for x, y in points)