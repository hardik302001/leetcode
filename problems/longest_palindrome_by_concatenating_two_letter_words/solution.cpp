class Solution {
public:
   
    int longestPalindrome(vector<string>& words)
    {
        int n = words.size() ;
        
        unordered_map<string,int> mp ; // map to store frequency of each word
        
        for(string x : words)
        {
            mp[x]++ ;
        }
        
  
        
        int count = 0 ;
        bool flag = false ; // assume that we have no suitable word w such that z = awb is a palindrome where b = reverse(a)
        
        for(auto p : mp)
        {
            string x = p.first ; // x ->current string
            
            string y = x ;
            reverse(y.begin(),y.end()) ; // y -> reverse of current string
            if(mp.count(y)){
                if(x!=y) // if x is not a palindrome
                {
                    // let the final string(palindrome) is z = awb , where w can be a empty string
                    //then
                    // if we want to place x in a , we should have one y (=reverse(x)) to place it in corresponding position in b inorder to maintain palindrome property
                    // so if frequency of x is 10 and frequency of y is 5,
                    // then we can only use 5 x and 5 y
                    int c = min(mp[x],mp[y]) ;
                    count+=c ; // count stores number of words present in a (where final answer z = awb)
                    // cout<<count<<" "<<c<<endl;
                    mp[y]-=c ; mp[x]-=c ; // we have used c occurances of x and y , so decrease its frequency

                }
                else
                {   // if x is a palindrome
                    // let frequency of x be 10, then
                    // we can use only 5 x in a, because we need 5 x in b
                    count+=mp[x]/2 ;

                    // if we have 11 x (odd number of x)
                    // we use 5 x in a, 5 x in b
                    // and the remaining x can be used in w 
                    // so make flag = true 
                    if(mp[x]%2==1)
                        flag = true ;

                    // we have used all the x, so reduce the frequency
                    mp[x] = 0;
                }
            }
                
        }
        
        // count is the number of words in a
        // number of words in b = number of words in a = count
        // number of words in a and b = 2*count
        // each word has 2 characters
        // number of characters in a and b = 2*2*count = 4*count
        int ans = count*4 ;
        
        // if we had got some word that can be placed in w
        // then length of final answer will be increased by 2
        if(flag)
            ans+=2 ;
        
        return ans ;
        
    }
};