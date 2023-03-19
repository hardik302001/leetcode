class Solution:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        n = len(colors)
        INF = 10**18
        o = INF
        t = INF
        th = INF
        left = [ [INF, INF , INF] for i in range(n)]
        for i in range(n):
            if colors[i]==1:
                left[i][0] = 0
                o = i
                if(t!=INF):
                    left[i][1]=left[i-1][1]+1
                if(th!=INF):
                    left[i][2]=left[i-1][2]+1
            elif colors[i]==2:
                left[i][1] = 0
                t = i
                if(o!=INF):
                    left[i][0]=left[i-1][0]+1
                if(th!=INF):
                    left[i][2]=left[i-1][2]+1
            else:
                left[i][2] = 0
                th = i  
                if(t!=INF):
                    left[i][1]=left[i-1][1]+1
                if(o!=INF):
                    left[i][0]=left[i-1][0]+1
        o = INF
        t = INF
        th = INF
        right = [ [INF, INF, INF] for i in range(n)]
        for i in range(n-1,-1,-1):
            if colors[i]==1:
                right[i][0] = 0
                o = i
                if(t!=INF):
                    right[i][1]=right[i+1][1]+1
                if(th!=INF):
                    right[i][2]=right[i+1][2]+1
            elif colors[i]==2:
                right[i][1] = 0
                t = i
                if(o!=INF):
                    right[i][0]=right[i+1][0]+1
                if(th!=INF):
                    right[i][2]=right[i+1][2]+1
            else:
                right[i][2] = 0
                th = i  
                if(t!=INF):
                    right[i][1]=right[i+1][1]+1
                if(o!=INF):
                    right[i][0]=right[i+1][0]+1
                    
        ans = [ [INF, INF, INF] for i in range(n)]
        for i in range(n):
            for j in range(3):
                ans[i][j] = min(left[i][j], right[i][j])
       
        res = []
        for a, b in queries:
            x = ans[a][b-1]
            if x==INF: x = -1
            res.append(x)
        return res
            
        