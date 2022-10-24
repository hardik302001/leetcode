//very similar to https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/


class Solution {
public:
        
    bool self(string str){           //if string itself have repaeted chars
            
         vector<int> freq(26,0);
         for(char c:str){
            if(freq[c-'a']==0){
               freq[c-'a']++;  
            }
            else return false;     
         }   
     return true;               
    }
        
    bool checkunique(unordered_set<char> &s,string str){
            
         for(char c:str){
             if(s.find(c)!=s.end()){
                 return false;
             }
         }
            
      return true;       
    }    
        
    void concatenation(vector<string> &arr,unordered_set<char> &s,int i,int &ans){
       
        if(i==arr.size()){
             return ;  
        }  
        if(self(arr[i]) && checkunique(s,arr[i])){
                
          for(auto c:arr[i]) s.insert(c);
          concatenation(arr,s,i+1,ans);
                
          if(s.size()>ans){
             ans=s.size();
          }      
          for(auto c:arr[i])s.erase(c);         //backtracking
        } 
        
        
        concatenation(arr,s,i+1,ans);          // ignore the prev arr[i], and now continue with arr[i+1]     
    }    
    
        
    int maxLength(vector<string>& arr){
        int ans=0;
        unordered_set<char> s;
        concatenation(arr,s,0,ans); 
            
        return ans;       
    }
};