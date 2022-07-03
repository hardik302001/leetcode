class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        alp = "abcdefghijklmnopqrstuvwxyz"
        d ={}
        key = "".join(key.split(" "))
        x = 0
        for i in key:
            if x==26:
                break
            if i not in d:
                d[i] = alp[x]
                x+=1
                
            else:
                continue

        ans = ""
        for i in message:
            if i==" ":
                ans+=" "
            else:
                ans+= d[i]
        return ans