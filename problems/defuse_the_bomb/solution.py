class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        arr =  code + code
        ans = []
        if k>=0:
            for i in range(n):
                ans.append(sum(arr[i+1: 1+i+k]))
        else:
            for i in range(n):
                ans.append(sum(arr[i +n +k: i +n]))
            
            
            
        return ans