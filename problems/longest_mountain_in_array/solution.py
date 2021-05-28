class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        peak = []
        maxi = 0
        n = len(arr)
        i = 1
        while i<=n-2:
            if arr[i]>arr[i+1] and arr[i]>arr[i-1]:
                #so its a peak
                #now traverse formt and back and take the count
                
                cnt = 1  #the peak element
                j = i   #pos of peak eleemnt
                
                
                #traverse back...dec j ..bcz j is our pointer to traverse back
                while j>=1 and arr[j] > arr[j-1]:
                    j = j -1
                    cnt +=1
                
                #traverse front and inc i..bcz i is our main pointer
                while i<=n-2 and arr[i]>arr[i+1]:
                    i = i +1
                    cnt = cnt +1
                maxi = max(maxi,cnt)
            else:
                i = i + 1
        return maxi