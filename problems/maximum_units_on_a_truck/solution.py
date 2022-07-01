class Solution:
    def maximumUnits(self, box: List[List[int]], truckSize: int) -> int:
        box.sort(key=lambda x:-x[1])        #we want maximum noofunits only..so our priority to maximise it..
        
        s=0
        for i,j in box:
            i=min(i,truckSize)
            s+=i*j
            truckSize-=i
            if truckSize==0:
                break
        return s