class Solution:
    def minSessions(self, tasks: List[int], t: int) -> int:
        
        tasks.sort(reverse = True)
        s = set(tasks)
        dic = {}
        for i in tasks:
            if i in dic:
                dic[i]+=1
            else:
                dic[i]=1
                
        count = 0
        
        for hr in tasks :
            if dic[hr] > 0 :
                
                dic[hr] -= 1
                curr = hr
                temp = t-curr
                while curr < t :
                    if temp in s and dic[temp] > 0: 
                        curr += temp
                        dic[temp] -= 1
                    else :
                        temp -= 1
                        if temp == 0:
                            break
                count += 1
        return count