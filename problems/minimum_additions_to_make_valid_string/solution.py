# same idea as lee215 , but different implementation : https://leetcode.com/problems/minimum-additions-to-make-valid-string/discuss/3421831/JavaC%2B%2BPython-Easy-and-Concise-with-Explanation

class Solution:
    def addMinimum(self, word: str) -> int:
        def check(aa, bb, cc):
            
            # removing common occurence
            a = aa>0
            b = bb>0
            c = cc>0
            if a==0 and b==0 and c==0: return 0
            if a==0 and b==0 and c==1: return cc
            if a==0 and b==1 and c==0: return bb
            if a==0 and b==1 and c==1: return bb+cc-1
            if a==1 and b==0 and c==0: return aa
            if a==1 and b==0 and c==1: return aa+cc-1
            if a==1 and b==1 and c==0: return aa+bb-1
            if a==1 and b==1 and c==1: return aa+bb+cc-2       
        
        m = 0
        cur = 'a'
        a = 0
        b = 0
        c = 0
            
        # minimum times we can have "abc" in increasing sequence
        for i in word:
            if i>=cur:
                if i=='a'  : a+=1
                elif i=='b': b+=1
                else       : c+=1
                cur = i
            else:   # start again bcz we got a dec sequence
                m = m + check(a, b, c)
                a , b , c = 0, 0 , 0
                cur = i
                if i=='a'  : a+=1
                elif i=='b': b+=1
                else       : c+=1
                cur = i
                       
        m = m+check(a, b, c)
        
        p = "abc"*(m) 
        return len(p) - len(word)
        