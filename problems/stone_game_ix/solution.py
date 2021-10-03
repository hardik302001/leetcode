# The first step is to consider each element after modulo 3.

# This approach considers what is the maximum sequence length you can get from the stones.

# We can assume there is no zeros for now.

# If Alice starts with taking a one, to avoid getting 0 mod 3 the sequence is

# [1] 1 2 1 2 1 2 1 2 (... ending with 1 or 2)

# If Alice starts with taking a two, to avoid getting 0 mod 3 the sequence is

# [2] 2 1 2 1 2 1 2 1 (... ending with 1 or 2)

# If there are no ones or twos at the start, Alice cannot pick any stone and Bob wins.
# If the sequence length is equal to the total number of stones, Bob wins (see question).
# If the sequence length is odd, the last stone is taken by Alice, Alice wins.
# If the sequence length is even, the last stone is taken by Bob, Bob wins.

# If Alice can choose a winning sequence, Alice wins.

# How do zeroes change the game?

# After Alice first takes the first one or two, either player can take a zero. The sequence length is simply extended by the number of zeroes.

class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        stones = [x%3 for x in stones]        
        c = Counter(stones)
        

        # 2 2 1 2 1 2 1 2 ... 0 0 0 0
        
        if c[2]:
            len_sequence = c[0]   #using all zeros at end
            c[2] -= 1
            len_sequence += 1    #starting the sequence with 2
            now_2 = True
            while True:
                if now_2:
                    if c[2]:
                        c[2] -= 1
                        len_sequence += 1
                    else:
                        break
                else:
                    if c[1]:
                        c[1] -= 1
                        len_sequence += 1
                    else:
                        break
                now_2 = not now_2
                
            print("start 2", len_sequence)
            if len_sequence == len(stones):
                pass
            elif len_sequence%2:  # last stone drawn by alice
                return True
            
        c = Counter(stones)
        # 1 1 2 1 2 1 2 ...0 0 0 0 0 .
        if c[1]:
            len_sequence = c[0]   #for allll zeros at end
            c[1] -= 1
            len_sequence +=1   #starting with 1 at beginning
            
            now_1 = True
            while True:
                if now_1:
                    if c[1]:
                        c[1] -= 1
                        len_sequence += 1
                    else:
                        break
                else:
                    if c[2]:
                        c[2] -= 1
                        len_sequence += 1
                    else:
                        break
                now_1 = not now_1
                
            print("start 1", len_sequence)
            if len_sequence == len(stones):
                pass
            elif len_sequence%2:  # last stone drawn by alice
                return True

            
        # no ones and twos
        return False
    
    
    
'''
    
Initially , when we started sequence by 2(the first case ),
If len_sequence == len(stones) it means that we have used all stones and still we did not got sum div by 3, so BOB wil win.

But we did pass because we want optimal solution. It may be possible that when we make sequence starting by 1 (the second case ), then maybe ALICE will win, So after checking that case also then we returned FALSE at very end.


Secondly, after checking for equal length we did elif len_sequence%2, it means we have not used all stones, and length of sequence is odd , so ALICE played her move, now BOB have to play his move and stones are available , so BOB have to play such that move that will lead to sum div by 3, so instantly ALICE WILL WIN.    
    
'''