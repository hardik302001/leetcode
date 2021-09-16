class Solution:
    def hasGroupsSizeX(self, deck):
        dict1 = {}

        if len(deck) <= 1:
            return False

        for ele in range(len(deck)):
            if deck[ele] in dict1:
                dict1[deck[ele]] = dict1[deck[ele]] + 1
            else:
                dict1[deck[ele]] = 1

        sets =  set(dict1.values())

        def gcd(a,b):

            while(b):
                a, b = b , a%b
            return a

        # To find GCD of elements in sets

        g = list(dict1.values())[0]

        for i in sets:
            g = gcd (g,i)
        if g<2:
            return False
        else:
            return True