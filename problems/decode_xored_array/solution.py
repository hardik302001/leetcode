'''According to Xor property
The inverse is XOR!

If you have:

c = a^b;
You can get a or b back if you have the other value available:

a = c^b; // or b^c (order is not important)
b = c^a; // or a^c

encoded[i] = arr[i] ^ arr[i+1]

Here we have an encoded array, and we want a resultant array, so we can interchange

res[0] = first
res[i+1] = res[i] ^ encoded[i]
'''
class Solution:
    def decode(self, encoded, first):
        res = []
        for i in range(0,len(encoded)+1):
            res.append(0^first if i==0 else encoded[i-1]^res[i-1])
        return res