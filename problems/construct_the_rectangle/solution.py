class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        for l in range(int(area**0.5), 0, -1):   #starting from sqrt , bz then only minimum difference           
            if area % l == 0: 
                return [area // l, l]