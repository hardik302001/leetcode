// https://leetcode.com/problems/car-pooling/discuss/1430518/O(N2)-to-O(N)-or-c%2B%2B-or-explained

// soln 1: O(n2)

/*
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> fre;
        for(int i=0;i<trips.size();i++)
        {
            int j;
            for(j=trips[i][1];j<trips[i][2];j++)
            {
                fre[j]+=trips[i][0];
                if(fre[j]>capacity)
                {
                    return false;
                }
            }
        }
        return true;
     
    }
};

*/

// soln 2: O(n)

// iterate over the entire vector and add the starting index value to the index in the map and substract the ending index value from the map index.
//find the cumulative sum of the map and if at a particular point the sum is greater than capacity return false.

class Solution {
public:
bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> track;
        for (const vector<int>& v : trips) {
            track[v[1]] += v[0];
            track[v[2]] -= v[0];
        }
        
        int count = 0;
        for (auto it : track) {
            count += it.second;
            if (count > capacity) return false;
        }
        return true;
    }
};


