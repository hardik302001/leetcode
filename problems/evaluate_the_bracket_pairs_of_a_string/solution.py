class Solution:
    def evaluate(self, s: str, know: List[List[str]]) -> str:
        d = Counter()
        for i in know:
            d[i[0]] = i[1]
        ans = ''
        t = ''
        f = 0
        for i in s:
            if i==')':
                if t not in d:
                    ans+= '?'
                else:
                    ans +=  d[t]
                t = ''
                f = 0
            elif i=='(':
                f = 1
            else:
                if f:
                    t += i
                else:
                    ans += i
        return ans
                