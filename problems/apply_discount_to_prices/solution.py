class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        p = sentence.split()
        r = []
        for i in p:
            if len(i)>0 and i[0]=='$' and i[1:].replace('.','',1).isdigit():
                x = float(i[1:])
                x = x - (x*discount)/100
                x = round(x , 2)
                x = str(x)
                x+="0"   # bcz after round it wil be 0.5 not 0.50 and we want exactly 2 decimal place
                
                l = x.split(".")
                sz = len(l[0])
                r.append(str("$"+str(x[:sz+3])))
            else: r.append(i)
        ans = ""
        for i in r:
            ans+=str(i)
            ans+=" "
        
        return ans[:-1]