#also see cpp solution , thats good maybe

#INTERVAL SOLUTION
class Solution:
    def carPooling(self, trips: List[List[int]], capacity : int) -> bool:
        start_timings = sorted( [(trip[1], trip[0]) for trip in trips] )
        end_timings = sorted( [(trip[2], trip[0]) for trip in trips] )

        passengers = 0
        start = end = 0
        while( start < len(trips) ):
            if start_timings[start][0] < end_timings[end][0]:
                passengers += start_timings[start][1]
                start += 1

                if passengers > capacity:
                    return False
                
            else:
                passengers -= end_timings[end][1]
                end += 1
                #no need to check capacity condition here, bcz passangers will decrease only 
        

            # print(passengers, start_timings[start][0], end_timings[end][0])
            
        return True