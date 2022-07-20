class Solution:
    def nthUglyNumber(self, n: int) -> int:
        res = [1]
        i = 0   #keep track of 2
        j = 0   #keep track of 3
        k = 0   #keep track of 5
        
        #at every step we need min of num*2,num*3,num*4, where num can be any of the elmenet present in res
        
        while len(res)<n:
            x = min(res[i]*2,res[j]*3,res[k]*5)   

#we are taking min of res[i]*2 , res[j]*3, res[k]*5 , THING TO NOTICE IS that we are #considering res[alpha] everytime, why bcz we want only those number whose prime factor #are limited to 2, 3, 5 . Its like dp, we are following res[alpha] everytime bcz we know, #res[alpha] is valid candidate!

#in this pattern we will never get for example 14, (2*7), we get 2 but we want 7, so we #wont get minimum element when i = 7,bcz res[alpha] would be only having 2 , 3, 5 as valid #candidates..  
            res.append(x)
            if x==res[i]*2:
                i+=1 
            if x==res[j]*3:
                j+=1
            if x==res[k]*5:
                k+=1
            # print(i,j,k)
        print(res)
        return res[n-1]
    
    
    #we are taking 3 independent if , bcz suppose we got 6, so we can get 6 by 3*2 and 2*3, so we need to increment both i and j , else there will be redundant values in res array!
    
    
# here its a dp soln, we would always have such res[alpha], that will ahve only prime factor as 2 3 5 only..so we make our soln for n, and print answer
#but what if we want factors, of 2 3 5 or nos divisible by 2 3 5 , and find nth eleemnt of that sequence.. 
#IN that case answer would not depend on res[alpha]...

'''
FOR MORE INFO VISIT UGLY NUMBER III
I did the basic soln, idea same as above soln,  ended up with TLE...
In that ques there is trick...visit there!

'''