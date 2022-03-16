class Solution:
    def numOfBurgers(self, t: int, c: int) -> List[int]:
        if (t-2*c)%2==0:
            if (t-2*c)//2 >=0 and  (4*c-t)//2>=0:
                return [(t-2*c)//2 , (4*c-t)//2]
            else:
                return []
        else:
            return []