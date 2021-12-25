class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        m = 0
        for i in sentences:
            p = i.split(' ')
            m = max(m , len(p))
        return m