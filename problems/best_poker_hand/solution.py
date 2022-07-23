class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        sui = Counter(suits)
        ran = Counter(ranks)
        
        for i in sui:
            if sui[i]==5:
                return "Flush"
        for i in ran:
            if ran[i]>=3:
                return "Three of a Kind"
        for i in ran:
            if ran[i]==2:
                return "Pair"
        
        return "High Card"