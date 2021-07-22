class Solution:
    def canPlaceFlowers(self, f: List[int], n: int) -> bool:
        if 1 not in f:
            return (len(f)+1)//2    >= n
        
        s = ''
        for i in f:
            s+=str(i)
        first = 0
        last = len(s)-1
        for i in range(len(s)):
            if s[i]=='1':
                first = i
                break
        for i in range(len(s)-1,-1,-1):
            if s[i]=='1':
                last = i
                break
        print(first, last)
        get = 0
        get += (first)//2
        get = get + (len(s)-last-1)//2
        s = s[first:last+1]
        a = s.split('1')
        print(a)
        for i in a:
            if len(i)==0:
                continue
            d = len(i)
            if d>=3:
                get = get + (d-1)//2
                
        return get>=n
            
        
        return 1