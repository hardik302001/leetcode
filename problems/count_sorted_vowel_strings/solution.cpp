class Solution {
public:
    int arr[26][51];
   string vowel = "aeiou";
    int util(char c, int len, int n, string s){
        if(len == n)
        {
            cout<<s<<"\n";
            
            return 1;
        }
        
        if(arr[c-'a'][len]!=-1)
            return arr[c-'a'][len];
        int ans = 0;
          for(auto x : vowel){
            if(x>=c)  
            {  
                s+=x;
                ans+= util(x, len+1, n,s+x);
                s.pop_back();
            }
        }
        return arr[c-'a'][len] = ans;
    }
    int countVowelStrings(int n) {
      
       
        int ans = 0;
        
        for(int i=0;i<26;i++){
            for(int j=0;j<51;j++){
                arr[i][j] = -1;
            }
        }
        
        for(auto c : vowel){
            string s = "";
            ans+= util(c, 1, n, s+c);
        }
        
        return ans;
        
        
    }
};