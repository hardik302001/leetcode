# encrypter easy peasy
# decrypter : dictiionary ke saare word ka encrypter string nikal ke uska count map me store kr do
# and then sirk map mei se count return kr do


class Encrypter:

    def __init__(self, keys: List[str], values: List[str], dic: List[str]):
        self.keys = keys
        self.values = values
        self.kv = {}
        for i in range(len(keys)):
            self.kv[keys[i]] = values[i]
            
        self.new = {}
        for word1 in dic:
            p = self.encrypt(word1)
            if p in self.new:
                self.new[p]+=1
            else:
                self.new[p] = 1

    def encrypt(self, word1: str) -> str:
        p = ''
        for i in word1:
            p+= self.kv[i]
        return p
        
        
    def decrypt(self, word2: str) -> int:
        if word2 in self.new:
            return self.new[word2]
        else:
            return 0


# Your Encrypter object will be instantiated and called as such:
# obj = Encrypter(keys, values, dictionary)
# param_1 = obj.encrypt(word1)
# param_2 = obj.decrypt(word2)