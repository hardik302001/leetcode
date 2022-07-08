 


# U CAN DO BRUTE
# OPTIMIZATION  1 : 
# COUNTING SORT AND PREF SUM: IN QUES MENTIONED 1  TO 100   (O(n))

# method 2:
# Sorting+dictionary   O(nlogn)


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
	    dic = {}
	    sorted_list = sorted(nums)
	    l = len(nums)
	    for i in range(0, l):
		    if sorted_list[i] not in dic:
			    dic[sorted_list[i]] = i
	    return [dic[n] for n in nums]



# linear time complexity and constant space
# def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
# 	smaller = [0]*101
# 	l = len(nums)
# 	for i in range(0, l):
# 		smaller[nums[i]]+=1

# 	for n in range(1, 101):
# 		smaller[n]+=smaller[n-1]

# 	for i in range(0, l):
# 		nums[i] = smaller[nums[i]-1] if nums[i]!=0 else 0
# 	return nums