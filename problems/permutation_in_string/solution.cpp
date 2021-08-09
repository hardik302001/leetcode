//EXACT SAME QUES: https://leetcode.com/problems/find-all-anagrams-in-a-string/
//ust changed the return value


class Solution {
public:
    bool checkInclusion(string p, string s) {  //also cahnge the string s and string p, in this question it is interchanged
        vector<int> v;
		if(s.size()<p.size())
		return bool(v.size());
		
        vector<int> arr(26,0);
        vector<int> brr(26,0);

        for(int i=0;i<p.size();i++)
		{
            brr[p[i]-'a']++;
        }
        
        int n=p.size();
        int left=0;
        for(int i=0;i<s.size();i++)
        {
            if(i<n-1){         //while size is less than size of susbtring
                arr[s[i]-'a']++;
            }
            else
            {
                arr[s[i]-'a']++;       //now size is same, time to check if they are sam eor not!
                if(arr==brr){
                    v.push_back(i-n+1);   //if same then push the relative starting index of substring
                } 
                
                arr[s[left]-'a']--;          //remove starting element of substring(now size of substring is one less than the                                                 //actual substring with which we will compare! )
                left++;                      //move one posi ahead
    
            }        
        }
        return bool(v.size());
    }
    
};