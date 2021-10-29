# see cpp soln, thats somewhat better maybe..
#sliding window


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = j = max_len = 0
        ss = set()
        while j < len(s):
            if s[j] in ss:
                ss.remove(s[i])
                i+=1                               #we are increasing i here, not j
                # suppose s[j] was not s[i] , for ex: "abcdb" , so i = 0, j = 4 , but "b" exist in map, so we update 
                # remove s[i] ans i = i +1, but still "b" exists
                
                #it means we aren't moving j until we remove the repeated key, we are using same loop to updatei and j both!
                
            else:
                ss.add(s[j])
                j+=1
                max_len = max(max_len, j-i)  
        return max_len