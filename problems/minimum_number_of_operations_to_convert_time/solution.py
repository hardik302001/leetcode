class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        cuh = int(current[:2])
        cum = int(current[3:])
        corh = int(correct[:2])
        corm = int(correct[3:])
        p = cuh*60 + cum
        q = corh*60 + corm
        
        return (q-p)//60 + ((q-p)%60)//15 +  (((q-p)%60)%15)//5 +  (((q-p)%60)%15)%5
        