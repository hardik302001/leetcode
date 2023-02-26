class Solution:
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        d = collections.defaultdict(list)    # store website records for each user
        c = collections.Counter()            # count how many websites a user visited
        for u, t, w in zip(username, timestamp, website): 
            d[u].append((t, w))
            c[u] += 1
        three_seq_cnt = collections.defaultdict(int)  # counter for three-sequences
        for u, records in d.items():            
            records.sort()                            # sort the record by time
            visited = set()                           # if some 3-sequence appears multiple times for one person, it only counts once
            for i in range(c[u]):                     # brutal force generate all 3-sequences
                for j in range(i+1, c[u]):
                    for k in range(j+1, c[u]):
                        three_seq = (records[i][1], records[j][1], records[k][1])
                        if three_seq in visited: continue  # avoid count multiple times
                        three_seq_cnt[three_seq] += 1
                        visited.add(three_seq)
        # sort all 3-sequence count and return                         
        ans = sorted(three_seq_cnt.items(), reverse=True, key=lambda x: (-x[1], x[0]))
        return ans[-1][0]