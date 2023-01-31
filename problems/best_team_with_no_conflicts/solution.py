class Solution(object):
	def bestTeamScore(self, scores, ages):
		"""
		:type scores: List[int]
		:type ages: List[int]
		:rtype: int
		"""
		score_age = sorted([[age, score] for age, score in zip(ages, scores)])

		dp = [0]*len(score_age)
		for i in range(len(scores)):
			dp[i] = score_age[i][1]
			for j in range(i):
				if score_age[i][1] >= score_age[j][1]:
					dp[i] = max(dp[i], score_age[i][1] + dp[j])

		return max(dp)
        