class Solution:
    def numTeams(self, rating: List[int]) -> int:
        asc = dsc = 0
        for i,v in enumerate(rating):
            llc = rgc = lgc = rlc =0
            for l in rating[:i]:
                if l < v:
                    llc += 1
                if l > v:
                    lgc += 1
            for r in rating[i+1:]:
                if r > v:
                    rgc += 1
                if r < v:
                    rlc += 1
            asc += llc * rgc
            dsc += lgc * rlc            
        return asc + dsc