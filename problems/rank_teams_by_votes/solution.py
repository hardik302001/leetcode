class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        votesDict = {}
        #get votes and store each teams votes in an array
        #such that votesDict[team] = [#votes in rank 1, #votes in rank 2, .... #votes in rank n] up to the length
        #of the vote string
        for vote in votes:
            for rank in range(len(vote)):
                team = vote[rank]
                if team not in votesDict:
                    votesDict[team] = [0] * len(vote)

                votesDict[team][rank] += 1
        # print(votesDict)

        #sort the team names alphabetically
        sortedTeamNames = sorted(list(votesDict.keys()))  # incase if its equal we have lexographic smaller key ahead
        
        # print(sortedTeamNames)
        # we sort based on votes
        #sorted(sortedTeamNames, key= votes[team] is an array which we will sort by)
        #if two or more teams have same vote count, it will return the original ordering in the sortedTeamNames
        #aka it will sort them alphabetically
        result = sorted(sortedTeamNames, key = lambda x: votesDict[x], reverse=True)
        return "".join(result)

        #extra explanation for how sorted sorts arrays:
        #ex: {'A': [5, 0, 0], 'B': [0, 2, 3], 'C': [0, 3, 2]} this is a count of the votes for 3 teams
        #for each team we get an array of the votes at any rank
        #if the we have the same array (ea: the same votes for each rank) it will get the ordering in the sortedTeamNames
        #meaning it will sort them alphabetically
        #if one array is > than the other (ie. the votes for any of the previous ranks comparing teams is strictly greater)
        #it gets placed first in our result
        #ex: A: [0, 5, 2, 1] vs B: [0, 5, 2, 2], B would get placed first since at index 3 B[3] > A[3]
        #so our resulting order be would [B, A]