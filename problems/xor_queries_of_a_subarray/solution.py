class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        pre = []
        pre.append(arr[0])
        ans = []
        for i in range(1,len(arr)):
        #    print(i)
            t = arr[i]^pre[i-1]
            pre.append(t)
    #print(pre)
        for i in queries:
            b = i[0]
            e = i[1]
            if b==0:
                ans.append(pre[e])
            else:
                res = pre[b-1]^pre[e]
                ans.append(res)
        return ans