class Solution:
    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        score, cals = 0, sum(calories[0: k])
        if cals > upper: score += 1
        if cals < lower: score -= 1

        for i in range(k,len(calories)):
            cals = cals+calories[i]-calories[i-k]
            if cals > upper: score += 1
            if cals < lower: score -= 1

        return score        