# https://leetcode.com/problems/group-anagrams/discuss/1398888/C%2B%2BPython-Group-by-sorted-string-group-by-count-characters-Solutions-Clean-and-Concise


# class Solution:
#     def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
#         def getKey(s):
#             cnt = [0] * 26
#             for c in s: cnt[ord(c) - ord('a')] += 1
#             ans = []
#             for i in range(26): ans.append(cnt[i] * chr(i + ord('a')))
#             return "".join(ans)

#         groups = defaultdict(list)
#         for s in strs:
#             groups[getKey(s)].append(s)
#         return groups.values()



class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def getKey(s):
            cnt = [0] * 26
            for c in s: cnt[ord(c) - ord('a')] += 1
            return tuple(cnt)

        groups = defaultdict(list)
        for s in strs:
            groups[getKey(s)].append(s)
        return groups.values()