class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:

        slots1.sort()
        slots2.sort()
        pointer1 = pointer2 = 0

        while pointer1 < len(slots1) and pointer2 < len(slots2):
            # find the boundaries of the intersection, or the common slot
            intersect_right = min(slots1[pointer1][1], slots2[pointer2][1])
            intersect_left = max(slots1[pointer1][0],slots2[pointer2][0])
            if intersect_right - intersect_left >= duration:
                return [intersect_left, intersect_left + duration]
            # always move the one that ends earlier
            if slots1[pointer1][1]< slots2[pointer2][1]:
                pointer1 += 1
            else:
                pointer2 += 1
        return []
    
    
    '''
    
    # line sweep
    
class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        times = []
        for s1, e1 in slots1:
            times.append((s1, 1))
            times.append((e1, -1))
        for s2, e2 in slots2:
            times.append((s2, 1))
            times.append((e2, -1))
        times.sort()
        currTime, currStatus = 0, 0
        for time, status in times:
            if currStatus == 2 and time - currTime >= duration:
                return [currTime, currTime + duration]
            currStatus += status
            currTime = time
        return []
    
    
    
    
    '''