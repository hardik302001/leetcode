class Solution:
    def escapeGhosts(self, ghosts, target):
        target_dist = abs(target[0]) + abs(target[1])
        
        for r, c in ghosts:
            ghost_target = abs(target[0] - r) + abs(target[1] - c)
            if ghost_target <= target_dist:
                return False
            
        return True