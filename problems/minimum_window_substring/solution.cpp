//see editorial



class Solution {
private:
    bool isMatchingHashCode(map<char,int>& smap,map<char,int>& tmap){
        for(auto it = tmap.begin(); it != tmap.end(); ++it){
            char c= it->first; int freq = it->second;
            if(smap[c] <freq)
                return false;
        }
        return true;
    }
    
public:
    string minWindow(string s, string t) {
        
        map<char,int> tmap,smap;
        for(char c : t) tmap[c]++;
        //tmap is the hashcode
        
        int start=0,end=0,counter=t.size(),minStart=0,minLen=INT_MAX;
        // counter represents the number of chars of t to be found in s.
        int size = s.size();
        
        while(end<size){
            smap[s[end]]++;; //add the freq of the char to smap 
            end++; //window to the right
            
            //by this time, if we have reached the matching substring, we will start resizing. If not, then the window has been expanded on the right size and its proceeding
            while(isMatchingHashCode(smap,tmap)){
                if(end-start<minLen){
                    minStart=start;
                    minLen = end-start;
                } //update the head and tail and length if needed, else, continue resizing
                smap[s[start]]--; //going left 
                start++;
            }
            
        }
        
        if(minLen!=INT_MAX){
            return s.substr(minStart,minLen);
        }
        return "";
        
    }
};

//one optimization that can be done is that we are again and again cross checking both hashmap, it is time consuming..wecan use only single hashmap to verify the same