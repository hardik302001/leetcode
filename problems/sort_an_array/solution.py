#bucket sort


#see the most bvotes comment in discuss

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        dic = {i:0 for i in range(-50000, 50001)}
        for i in nums:
            dic[i] += 1
        res = []
        for i in dic:
            for j in range(dic[i]):
                res.append(i)

        return res