#basically brute force, but still IT IS GOOD!


#here variablity is toppings
#we want combinations of toppings, bcz base is fixed(we need exactly one) and we can have more types of toppings over one another

class Solution:
    def closestCost(self, baseCosts: List[int], toppingCosts: List[int], target: int) -> int:
        costs = set(baseCosts)
        for topping in toppingCosts:
            withToppingCosts = []
            for c in costs:           #all combo of toppings with ( all bases )  
                withToppingCosts.append(c)
                withToppingCosts.append(c+topping)
                withToppingCosts.append(c+topping*2)
            costs = set(withToppingCosts)           #now costs is new icecream base( one actual icecream base + some previously available toppings )
            # print(costs)
        
        # Set now contains all the possibilitys. Pick the best one.
        best = baseCosts[0]
        for c in costs:
            if abs(c-target) < abs(best-target):
                best = c
            elif abs(c-target) == abs(best-target) and c < best:
                best = c
        return best