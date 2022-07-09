# we need latest time, so we need to start looking from last bus
# we need to see if there is some space empty at last bus, if yes then get seated there only,
# else start looking in last second bus



class Solution:
    def latestTimeCatchTheBus(self, bus: List[int], pas: List[int], capacity: int) -> int:
        bus.sort()
        pas.sort()
        
        x = 0         # here x is pointer for passanger
        # we will arrange them according to the capacity and bus
        
        last = []     # passanger arrival time in last bus
        
        
        # get all passangers seated in bus
        for i in range(len(bus)):   # i is pointer for bus
            if i==(len(bus)-1):
                c = 0
                while x<len(pas) and pas[x]<=bus[i] and c<capacity:
                    last.append(pas[x])
                    x+=1
                    c+=1
                
            else:
                c = 0
                while  x<len(pas) and pas[x]<=bus[i] and c<capacity:
                    x+=1
                    c+=1
        
        
        # now we got passangers arrival time in last bus, 
        s = set(pas)      
        
        if len(last)==capacity:
            lastest_arrival_time = last[-1] # it all seats are occupied, we cant look for any latest time than ans[-1], bcz seat is full, even if we get ny valid time, we wont be able to use it
        else:
            lastest_arrival_time = bus[-1] # we will start looking for that time when bus will depart
            
        while len(s) and lastest_arrival_time in s:  # bcz time shud not conflict
            s.remove(lastest_arrival_time)
            lastest_arrival_time-=1
            
            
        return lastest_arrival_time
                
                