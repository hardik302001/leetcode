class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> m;
        for (auto c: s) ++m[c];
        int n = s.size();
        
        unordered_map<char, int> remain;
        string t;
        for (auto it: m){
            if (it.second > n/4){
                remain[it.first] = it.second - n/4;
                for(int i = 0;i<(it.second -n/4);i++){
                    t.push_back(it.first);
                }
            }
        }   
        if (remain.empty()) return 0;
        else{
            string ans = minWindow(s, t);
            return ans.size();
        }        
    }
    
    
    string minWindow(string s, string t) {
        
        vector<int> tmap(128,0), smap(128,0);      //128 bcz ascii A = 65, ascii a = 97 , so large gap
        for(char c : t) tmap[c- 'A']++;  //why -'A' only, why not 'a'..??
                                        // to keep indexes positive 
                                        //  bcz ascii of 'A' < ascii of 'a' 
                                        //so relatively s[i]-'A' = 0 , if we take s[i]-'a' = 0, then s[i]-'A' will be negative and we cant have negative indexes
        //tmap is the hashcode
        
        int start=0,end=0,counter=t.size(),minStart=0,minLen=INT_MAX;
        int c = 0;
        // counter represents the number of chars of t to be found in s.
        int size = s.size();
        
        
        while(end<size){
            smap[s[end]-'A']++; //add the freq of the char to smap 
            if(tmap[s[end]-'A']>=smap[s[end]-'A']) {   //no. of valid chrs from string t, that are occuring in string s! so we update c till freq of chars are less than equal to freq of char of string t
                c++;
            }   
            //cout<<s[end]<<" "<<c<<endl;
            
            //by this time, if we have reached the matching substring, we will start resizing. If not, then the window has been expanded on the right size and its proceeding
            while(c==counter){        //when freq equates than do sliding
                if(end-start+1<minLen){  //update result
                    minStart=start;
                    minLen = end-start+1;
                } //update the head and tail and length if needed, else, continue resizing
                
                smap[s[start]-'A']--; //going left
                if(tmap[s[start]-'A'] > smap[s[start]-'A']){  //now if s[start] is a valid char,a nd it needs to be removed than  we also need to upadte c
                    c--;
                }
                start++;
            }
            
            end++;
        }
        
        if(minLen!=INT_MAX){
            return s.substr(minStart,minLen);
        }
        return "";
        
    }
};