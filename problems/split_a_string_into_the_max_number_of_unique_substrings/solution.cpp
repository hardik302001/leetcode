// similar to https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters



class Solution {
public:
    int max_unique_substrings(string s,unordered_set<string>&seen)
    {
        int maximum = 0;
        for(int i = 1;i<s.length() + 1;i++)
        {
			//simply take current substring as candidate and put it in seen if being seen for the 1st time
            string candidate = s.substr(0,i);
            if(seen.count(candidate) == 0)
            {
                seen.insert(candidate);
				//recur for the remaining substring
                maximum = max(maximum, 1 + max_unique_substrings(s.substr(i,s.size()),seen));
                seen.erase(candidate);//backtracking
            }
        }
        return maximum;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return max_unique_substrings(s,seen);
    }
};