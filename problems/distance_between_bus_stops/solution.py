class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, dest: int) -> int:
        clock = 0
        n = len(distance)
        while start!=dest:
            clock += distance[start]
            start +=1
            if start==n:
                start = 0
        
        return min(sum(distance)-clock , clock)