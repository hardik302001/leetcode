# https://leetcode.com/problems/describe-the-painting/discuss/1359717/Python-Easy-solution-in-O(n*logn)-with-detailed-explanation



class Solution:
    def splitPainting(self, segments: List[List[int]]) -> List[List[int]]:
		# via this mapping, we can easily know which coordinates should be took into consideration.
        mapping = defaultdict(int)
        for s, e, c in segments:
            mapping[s] += c
            mapping[e] -= c
            
        # print(mapping)
        map = sorted(mapping)
        print(map)
        res = []
        prev, color = None, 0
        for now in map:
            if prev is not None and color != 0: # if color == 0, it means this part isn't painted.
                res.append((prev, now, color))
            
            color += mapping[now]
            prev = now
            
        return res
    
    
    
    
    

    
    
    
    
    
    
    