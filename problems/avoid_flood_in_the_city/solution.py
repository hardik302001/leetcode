class Solution:
    def avoidFlood(self, rains):
        filled, dry_days = {}, []
        ans = [1] * len(rains)

        for day, lake in enumerate(rains):
            if not lake:
                dry_days.append(day)
                continue 

            ans[day] = -1
            if lake in filled:
                if not dry_days: return []
                # use the first dry day after the lake was filled (stored in filled[lake])
                dry_on_day_index = bisect.bisect_left(dry_days, filled[lake])
                if dry_on_day_index >= len(dry_days): return []
                dry_on_day = dry_days.pop(dry_on_day_index)
                ans[dry_on_day] = lake

            filled[lake] = day # we fill it on day

        return ans
