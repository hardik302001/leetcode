class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        s = set()
        for email in emails:
            local = email.split('@')[0]
            domain = email.split('@')[1]
            local = local.replace('.','')
            if '+' in local:
                ind = local.index('+')
                newlocal = local[:ind]
                final = newlocal + '@' + domain
            else:
                final = local + '@' + domain
            s.add(final)
        print(s)
        return len(s)