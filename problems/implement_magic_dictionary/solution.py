#see cpp solution for trie



#hashmap solution

class MagicDictionary:

    def __init__(self):
        self.d = {}

    def buildDict(self, dictionary: List[str]) -> None:
        for i in dictionary:
            l = len(i)
            if l in self.d:
                self.d[l].append(i)
            else:
                self.d[l] = [i]
        

    def search(self, searchWord: str) -> bool:
        ll = len(searchWord)
        if ll in self.d:
            l = self.d[ll]        
            for word in l:
                c = 0
                for i in range(ll):
                    if word[i]!=searchWord[i]:
                        c =c  +1
                if c==1:
                    return True
            return False
        return False


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dictionary)
# param_2 = obj.search(searchWord)