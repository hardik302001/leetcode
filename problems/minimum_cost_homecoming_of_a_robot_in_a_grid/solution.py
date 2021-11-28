class Solution:
    def minCost(self, startPos: List[int], homePos: List[int], rowCosts: List[int], colCosts: List[int]) -> int:
        src_x,src_y = startPos[0],startPos[1]
        end_x,end_y = homePos[0], homePos[1]

        if src_x < end_x:
            rc = sum(rowCosts[src_x+1:end_x+1])
        elif src_x > end_x:
            rc = sum(rowCosts[end_x:src_x])
        else:
            rc=0

        if src_y < end_y:
            cc = sum(colCosts[src_y+1:end_y+1])
        elif src_y > end_y:
            cc = sum(colCosts[end_y:src_y])
        else:
            cc=0

        return cc+rc