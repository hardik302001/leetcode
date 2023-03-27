# rolling hash 

class Solution:
    
    def function(self, s, width, total):
        left, dict1, result = 0, defaultdict(int), 0

        for right in range(len(s)):
            dict1[s[right]] += 1

            if right - left + 1 > width:
                dict1[s[left]] -= 1

                if dict1[s[left]] == 0:
                    del dict1[s[left]]

                left += 1

            if right - left + 1 == width and all([val == total for val in dict1.values()]):
                result += 1

        return result

    def equalCountSubstrings(self, s, count):
        res = 0

        for i in range(1,27):
            res += self.function(s, i*count, count)

        return res