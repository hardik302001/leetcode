class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        dict = {}
        for i, o in enumerate(order):
            dict[o] = i
			
        for i in range(1,len(words)):
            #flag = 1 here means inner loop is break out due to pre less than cur
			#flag = 0 here means inner loop done iteration but two strings length are not equal
            pre, cur, flag = words[i-1], words[i], 0
            for j in range(min(len(pre),len(cur))):
                if dict[pre[j]] < dict[cur[j]]:
                    flag = 1
                    break
                elif dict[pre[j]] > dict[cur[j]]:
                    return False
                
            if not flag and len(pre) > len(cur):    #if strimg are  equal , but pre is of longer size than cur, return  false 
                return False
            
            #else we just contnue for next words in words array
            
        return True