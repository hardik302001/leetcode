class Solution:
    def minNumberOfHours(self, initialEnergy: int, initialExperience: int, energy: List[int], experience: List[int]) -> int:
        c = 0
        n = len(energy)

        for i in range(n):
            
            if initialEnergy <= energy[i]:
                c += ( energy[i] - initialEnergy+1 )
                if i==(n-1):
                    initialEnergy = energy[i]
                else:
                    initialEnergy = energy[i]+1
            
            if initialExperience <= experience[i]:
                c += ( experience[i] - initialExperience+1 )
                if i==(n-1):
                    initialExperience = experience[i]
                else:
                    initialExperience = experience[i]+1

            initialEnergy -= energy[i]
            initialExperience +=experience[i]
            
        return c
        
        