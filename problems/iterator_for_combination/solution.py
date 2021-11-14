# https://leetcode.com/problems/iterator-for-combination/discuss/789190/Python-bit-manipulation-(Easy-to-understand)

#generate all bitmasks



class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.characters = characters
        self.n = len(characters)
        self.combinations = self.gen_combinations(self.n, combinationLength)
        print(self.combinations)
        self.ind = len(self.combinations) - 1

    def next(self):
        s = ""
        for i in range(self.n):
            if self.combinations[self.ind][i] != "0":
                s += self.characters[i]
        self.ind -= 1
        return s

    def hasNext(self):
        return self.ind > -1 
    
    def gen_combinations(self, l, k):
        end = int("1" * l, 2)
        print(end)
        ans = []
        for i in range(end + 1):
            b = bin(i)[2:]
            if b.count('1') == k:
                ans.append(b.zfill(l))              #fill zeros at beginning to make size k 
        return ans