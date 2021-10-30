//BINARY SEARCH AND RABIN KARP!




class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size(), l = 0, r = n;
        
        // binary search for length of longest substring cuz if duplicate substring of len k is present then substring of len k-1 would of course be present, so search for greater lengths
        string res;
        while(l < r) {
            string dup;
            int mid = l + (r - l) / 2;
            // cout<<mid<<endl;
            int d = rabinKarp(s, mid);
            if(d==-1){
                dup = "";
            }
            else{
                dup = s.substr(d, mid);             
            }
 
            if((int)dup.size() > (int)res.size()) {
                res = dup;
                l = mid+1;
            } else  r = mid;
        }
        return res;
    }
    
    
    
    
    int rabinKarp(string s, int len) {
        int n = s.size();
        int mod = 1000000007;
        unordered_map<long long int ,vector< int >>map;
        
        //PREPROCESSING
        vector<long long>power(n);
        for(int i = 0; i < n; i++)  power[i] = (i == 0) ? 1 : (power[i-1] * 31) % mod;

        vector<long long>hash(n+1,0);
        for(int i = 0;i<n;i++){
            hash[i+1] = (hash[i] + (s[i]- 'a' + 1)*power[i])%mod;
        }        
        

        
        // now find hash of all substrings of length len and match them..
        for(int i = 0;i+len-1 < n;i++){
            long long cur_h = (hash[i+len] - hash[i] + mod)%mod;
            cur_h = (cur_h * power[n-i-1]) % mod;    //last code on: https://cp-algorithms.com/string/string-hashing.html 
            //this is optimisation for RABIN CARP 
            
            if(map.count(cur_h)){
                for(int &index : map[cur_h]){
                        if(s.substr(index,len)==s.substr(i,len)){      //if hash matches, the string shud also match, else it is a colllison
                            return index;
                        }
                }
                    map[cur_h].push_back(i);        //we got a collision ,, so put it into vector
                
            }
            else{
                map[cur_h] = {i};
            }
            
            // for(auto it:map){
            //     cout<<it.first<<" "<<it.second<<" -> " ;
            // }
            //cout<<endl;
        }
        
        return -1;
   
    }
};