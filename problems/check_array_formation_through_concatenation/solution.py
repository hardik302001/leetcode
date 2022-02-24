class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        p = []
        d = Counter()
        for i in arr:
            d[i]+=1
        
        for i in arr:
            if d[i]==0:
                continue
            else:
                for piece in pieces:
                    if piece.count(i):
                        for x in piece:
                            d[x]-=1
                        
                        p.extend(piece)
        
        return p==arr