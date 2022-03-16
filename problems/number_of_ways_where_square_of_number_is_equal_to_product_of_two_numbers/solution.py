class Solution:
	def numTriplets(self, nums1: List[int], nums2: List[int]) -> int:
		d1 = collections.defaultdict(int)
		d2 = collections.defaultdict(int)
		for i in nums1:
			d1[i * i] += 1
		for i in nums2:
			d2[i * i] += 1
		res = 0
		for i in range(len(nums1)):
			for j in range(i + 1, len(nums1)):
				p = nums1[i] * nums1[j]
				if p in d2:
					res += d2[p]
		for i in range(len(nums2)):
			for j in range(i + 1, len(nums2)):
				p = nums2[i] * nums2[j]
				if p in d1:
					res += d1[p]
		return res