# same as codechef : https://www.codechef.com/JULY20B/problems/CHFNSWPS?tab=submissions


class Solution:
    def minCost(self, a: List[int], b: List[int]) -> int:
        n = len(a)
        res = 0
        flag = 0

        freq_a = dict()
        freq_b = dict()
        combin = dict()

        for i in range (n):
            if a[i] not in freq_a:
                freq_a[a[i]] = 1
            else:
                freq_a[a[i]] += 1
            if b[i] not in freq_b:
                freq_b[b[i]] = 1
            else:
                freq_b[b[i]] += 1
            if a[i] not in combin:
                combin[a[i]] = 1
            else:
                combin[a[i]] += 1
            if b[i] not in combin:
                combin[b[i]] = 1
            else:
                combin[b[i]] += 1



        for i, j in combin.items():
            #for odd value break the loop and print -1
            if(j % 2 != 0):
                return -1
            #For even number of vakues...
            else:
                combin[i] = (j // 2)

      
        arr = []
        brr = []
        for i in freq_a.keys():
            if(freq_a[i] > combin[i]):
                k = (freq_a[i] - combin[i])
                #print(k)
                while(k):
                    arr.append(i)
                    k -= 1
        for i in freq_b.keys():
            if(freq_b[i] > combin[i]):
                m = (freq_b[i] - combin[i])
                #print(m)
                while(m):
                    brr.append(i)
                    m -= 1
    
        
        arr.sort()
        brr.sort(reverse = True)
        print(arr, brr, combin)
        d = min(combin.keys()) * 2
        for i in range(len(arr)):
            if(min(arr[i], brr[i]) > d):
                res += d
            else:
                res += min(arr[i], brr[i])
        return res
    
    
