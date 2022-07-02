class Solution:
    def maxArea(self, h: int, w: int, hc: List[int], vc: List[int]) -> int:
        mod = 1000000007
        hc.sort()
        vc.sort()        
        mh = hc[0]
        mv = vc[0]

        
        for i in range(1, len(hc)):
            mh = max( mh , hc[i]-hc[i-1])
        mh = max(mh , h-hc[-1])
        
        for i in range(1, len(vc)):
            mv = max( mv , vc[i]-vc[i-1])
        mv = max(mv , w-vc[-1])
        
        # print(mh , mv)
        return (mh%mod * mv%mod)%mod