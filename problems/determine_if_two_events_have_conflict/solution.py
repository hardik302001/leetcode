class Solution:
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        p = [event1, event2]
        p.sort()
        event1 = p[0]
        event2 = p[1]
        b1 = int(event1[0][:2])*60 + int(event1[0][3:])
        e1 = int(event1[1][:2])*60 + int(event1[1][3:])
        b2 = int(event2[0][:2])*60 + int(event2[0][3:])
        e2 = int(event2[1][:2])*60 + int(event2[1][3:])
        
        return b2<=e1