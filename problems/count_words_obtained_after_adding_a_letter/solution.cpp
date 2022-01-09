// Approach 1: Using HashSet+Sorting

// Sort all strings and insert them in a set.
// For target string take every string and search for all possible combinations of it by removing every character one by one.
// If found in set increase the count.
// Time Complexity : O(n*26log(26)) ~ O(n)
// Space Complexity: O(n)


    
class Solution
{
    public:
    unordered_set<string> st;
    bool isPossible(string& s)
    {
        int n=s.length();
        //take all possible string by removing 1 character and search them in given set
        for (int i=0;i<n;i++)
        {
            string temp="";
            for (int j=0;j<n;j++)
            {
                if (j==i)
                    continue;
                temp.push_back(s[j]);
            }
            if (st.find(temp)!=st.end())
                return true;
        }
        return false;
    }
    int wordCount(vector<string>& arr, vector<string>& target)
    {
        int n=target.size();
        for (auto& i:arr)
        {
            sort(i.begin(),i.end());  //Sort all strings and insert them in set
            st.insert(i);
        }
        
        int count=0;
        for (int i=0;i<n;i++)
        {
            sort(target[i].begin(),target[i].end());
            if (isPossible(target[i]))
                count++;
        }
        return count;
    }
};




// class Solution {
// public:
//     int wordCount(vector<string>& startWords, vector<string>& targetWords) {
//         unordered_map<string, int> target;
//         for(auto t: targetWords) {
//             sort(t.begin(), t.end());
//             target[t]++;
//         }
//         int ans = 0;
//         for(auto s: startWords)  {
//             for(char c = 'a'; c <= 'z'; ++c) {
//                 if(count(s.begin(), s.end(), c)) continue;
//                 auto t = s + c;
//                 sort(t.begin(), t.end());
                
//                 if(target.find(t) != target.end()) {
//                     ans += target[t];
//                     target.erase(t);
//                 }
//             }
//         }
//         return ans;
//     }
// };