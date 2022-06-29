// BOTH SOLN ARE O(n^2)
// https://leetcode.com/problems/queue-reconstruction-by-height/discuss/427157/Three-different-C%2B%2B-solutions.-from-O(n2)-to-O(nlogn).-faster-than-99.

/*
Solution 1:
We insert people one by one into an empty array. The number k is the position we need to insert. For everyone, we should first insert the higher h person. For the person who has same h we should first insert the person has small k value. For each inserted person, it takes O(n) time to move the person behind him back one position, so it will take the O(n^2) time for all people.
E.g.
input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
sort: [[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
step1: [[7,0]]
step2: [[7,0], [7,1]]
step3: [[7,0], [6,1], [7,1]]
step4: [[5,0], [7,0], [6,1], [7,1]]
step5: [[5,0], [7,0], [5,2], [6,1], [7,1]]
step6: [[5,0], [7,0], [5,2], [4,4], [6,1], [7,1]]
*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for(int i = 0; i < people.size(); i++){
            res.insert(res.begin()+people[i][1], people[i]);
        }
        return res;
    }
    static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]>p2[0];
        else return p1[1]<p2[1];
    }
};


//----------------------------------------------------------------------------

/*
Solution 2:
We put people in an array of length n. The number k means that we should put this person in the kth empty position from the beginning. The empty position mean that there will be higher or equal height person coming in here, so leave these positions out first. For everyone, we should first insert the lower h person. For the person who has same h we should first insert the person has larger k value. For everyone to put in, it takes O(n) time to find kth empty position, so it will take the O(n^2) time for all people.
E.g.
input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
sort: [[4,4], [5,2], [5,0], [6,1], [7,1], [7,0]]
step1: [[  ,  ], [  ,  ], [  ,  ], [  ,  ], [4,4], [  ,  ]]
step2: [[  ,  ], [  ,  ], [5,2], [  ,  ], [4,4], [  ,  ]]
step3: [[5,0], [  ,  ], [5,2], [  ,  ], [4,4], [  ,  ]]
step4: [[5,0], [  ,  ], [5,2], [6,1], [4,4], [  ,  ]]
step5: [[5,0], [  ,  ], [5,2], [6,1], [4,4], [7,1]]
step6: [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

/*
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res(people.size(), vector<int>());
        for(int i = 0; i < people.size(); i++){
            int cnt = 0;  //empty count start from 0
            for(int j = 0; j < res.size(); j++){ 
                if(res[j].empty()){
                    if(cnt==people[i][1]) break;
                    cnt++;
                }
            }
            res[j]=people[i];
        }
        return res;
    }
    static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]<p2[0];
        else return p1[1]>p2[1];
    }
};

*/