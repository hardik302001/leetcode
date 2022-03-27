class Solution:
    def kthPalindrome(self, queries: List[int], l: int) -> List[int]:
        ans = []
        p = (l+1)//2
        for q in queries:
            ma_pos = 9*(10)**(p-1)
            if q>ma_pos:
                ans.append(-1)
            else:
                first = int("1"+"0"*(p-1))
                print(first)
                if l&1==0:
                    kth = first + q-1
                    skth = str(kth)
                    ans.append(int(skth+ skth[::-1]))                    
                else:
                    kth = first + q-1
                    skth = str(kth)
                    ans.append(int(skth+ skth[:-1][::-1]))
        return ans