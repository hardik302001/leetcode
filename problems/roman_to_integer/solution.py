class Solution:
    def romanToInt(self, s: str) -> int:
        num_dict = {   'I' : 1,
                       'V' : 5,
                       'X' : 10,
                       'L' : 50,
                       'C' : 100,
                       'D' : 500,
                       'M' : 1000 }
        res=0
        i = 0
        
        while i < len(s)-1:
            if num_dict[s[i]] >= num_dict[s[i+1]]: # just add number to res
                res += num_dict[s[i]]
                i+=1
            else:
                res += num_dict[s[i+1]]-num_dict[s[i]] # if s[i]<s[i+1]: subtract from next number
                i+=2
                
        if i < len(s): # if last digit left
            res += num_dict[s[i]]
            
        return res