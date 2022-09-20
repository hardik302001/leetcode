'''
we want minimum amount regardless of order
so we would conisder that permutuation that would give us worst cost...

so 2 priorities:
1. consider cases where cost>cashback
2. if cost<=cashback, see if we can afford cost of that transaction to avail the cashback

'''


class Solution:
    def minimumMoney(self, transactions: List[List[int]]) -> int:
        re = 0
        m = 0
        for i in transactions:
            if i[0] - i[1] > 0: 
                re += i[0] - i[1]   # conisder negative profit from that transaction
                m = max(m, i[1])    # removing cashback of last transac
            else:   # conisder maximum cost
                m = max(m, i[0])
        return re + m
    
    
'''

we have to conisder all transac with neg profit ( cost - cashback ) anyways
but what we dont have to consider the positive profit contrib of cashback in LAST TRANSAC

consider perm : [[4,2],[2,1],[5,0]]
here we get re = 8
we only need total money = 8, to get all transac done

consider perm : [[4,2],[5,0],[2,1]]
here we get re = 8
we only need total money = 9, to get all transac done

consider perm : [[5,0],[2,1],[4,2]]
here we get re = 8
we only need total money = 10, to get all transac done
so it is the worst case perm, we need to consider

here, the positive profit from last transac ([4,2]) wont contribute in minimising the total money,
thats why we do this transaction at end

therefore, we consider max of cashback of all transaction with neg profit , to be our last transaction, and update our answer.

'''

# ---------------------------------------------------------

# similar idea: https://leetcode.com/problems/minimum-money-required-before-transactions/discuss/2588064/Simple-Python-Solution-with-explanation-just-5-lines-of-code-O(N)-time-complexity