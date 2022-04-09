//standard sliding window










// O(26*len(s))
class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
		vector<int> v;
		if(s.size()<p.size())
		return v;
		
        vector<int> arr(26,0);
        vector<int> brr(26,0);

        for(int i=0;i<p.size();i++)
		{
            brr[p[i]-'a']++;
        }
        
        int n=p.size();
        int l=0;
        for(int r=0;r<s.size();r++)
        {
            
            arr[s[r]-'a']++;       //now size is same, time to check if they are sam eor not!
            
            if(r-l+1>n){                             
                arr[s[l]-'a']--;          //remove starting element of substring(now size of substring is one less than the actual substring with which we will compare! )
                l++;                      //move one posi ahead
    
            }
            
            
            if(arr==brr){
                v.push_back(l);   //if same then push the relative starting index of substring                } 
            }

                  
        }
        return v;
    }
};



/*

//other short code 

vector<int> findAnagrams(string s, string p) {
	vector<int> goal(26), cur(26), res;
	for(char c : p) goal[c - 'a']++;
	for(int i = 0; i < s.size(); i++) {
		cur[s[i] - 'a']++;
		if(i >= p.size()) cur[s[i - p.size()] - 'a']--;
		if(cur == goal) res.push_back(i - p.size() + 1);
	}
	return res;
}
*/