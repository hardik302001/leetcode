class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
            cars = []
            for i in range(len(position)):
                cars.append((position[i], speed[i]))

            cars.sort(key=lambda x: (x[0], x[1]), reverse=True) # desc order : closer to target comes first
            stack = []
            for x, v in cars:
                dist = target - x # remaning distance to target
                if not stack:
                    stack.append(dist/v) # arrivalTime = dist/v
                elif dist/v > stack[-1]: # car is away from target as compared to prev car and it takes more time than prev car, so it will never cross it, so it will make a seperate fleet..car arrives late -> thus does not join previous fleet and forms its own fleet
                    stack.append(dist/v)
                    
                # if curr arrivalTime is <= prev arrivalTime -> then curr car joins prev fleet and gets discolved into it (aka we don't need to do anything)
            return len(stack)