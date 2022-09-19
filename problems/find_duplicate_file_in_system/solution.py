class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        h = defaultdict(list)
        while len(paths):
            p = paths.pop() # pop the item to avoid doubling of memory used.
            folder, files = p.split()[0], p.split()[1:]
            for f in files:
                s = f.split('(',maxsplit=1) # stops when '(' char is first encountered.
                fn, content = folder + '/' + s[0], s[1][:-1] #No need to use split when you know ')' is the last char
                h[content].append(fn)
        ans = []
        for k in h:
            if len(h[k]) > 1: ans.append(h[k])
        
        return ans