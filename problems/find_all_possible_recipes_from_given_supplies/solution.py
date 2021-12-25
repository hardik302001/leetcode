class Solution:
    def findAllRecipes(self, recipes: List[str], ing: List[List[str]], sup: List[str]) -> List[str]:
        c = set()
        sup = set(sup)
        n =len(recipes)

        for process in range(n):
            for i in range(n):
                recipe = recipes[i]
                f = 1
                for ind in ing[i]:
                    if ind not in sup:
                        f = 0
                        break
                if f:
                    c.add(recipe)
                    sup.add(recipe)
                    
        
                
        return list(c)
            