// classic recursion


class Solution {
public:
    bool splitString(string s) {
        for (int i = 1; i < s.size(); ++i) {
            long long int tar = stoull(s.substr(0, i));     // first 
            if (helper(s.substr(i, s.size()-i), tar))        //  ( second , first)
                return true;
        }
        return false;
    }
    
    bool helper(string s, long long int tar) {
        if (stoull(s) == (tar-1)) return true;
        
        for (int i = 1; i < s.size(); ++i) {
            long long int newtar = stoull(s.substr(0, i)); 
            if (newtar != (tar-1)){           // bcz diff is not 1 , so we ignore it
                continue;   
            }else{                            // now, newtar is equal to (tar -1) , so we will continue checking ahead
                if (helper(s.substr(i, s.size()-i), newtar))
                    return true;
            }
        }
        return false;
    }
};