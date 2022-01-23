# Actually n <= 15 is a very strong hint that we can try all combinations by brute force. So we can try every possible guess of the types of each person and check whether it's valid or not.

# The validation process is also very simple, since the bad person can tell the truth or lie whenever they want, which means his/her statements actually mean nothing, so we can just ignore it! We only need to take care those good person and check if any statements made by them have any contradiction with our current guess.

# Finally, we choose the guess with maximum good people without any contradiction.

class Solution:
    def validation(self, guessedTypes, statements):
        N = len(statements)
        for i, type in enumerate(guessedTypes):
            # We only need to take care the statements of good person
            if type == 1:
                for j in range(N):
                    # This statement is contradicted with our current guess
                    if statements[i][j] != 2 and statements[i][j] != guessedTypes[j]:
                        return False
        return True

    def maximumGood(self, statements: List[List[int]]) -> int:
        N = len(statements)
        ans = 0
        for i in range(1<<N):
            guessedTypes = [int(x) for x in bin(i)[2:].zfill(N)]
            if self.validation(guessedTypes, statements):
                ans = max(ans, sum(guessedTypes))
        return ans