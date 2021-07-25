//    Logic:- Simply For each permutation try to combine with pair and return the maximum of all the outcomes received.
//either permutatuate students, and compare with mentor or vice-versa..doesn't matter


class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
    
        vector<int>pos;
        for(int i=0;i<students.size();i++) pos.push_back(i);
        int ans=0;
          //first iteration bcz if length = 1, then there is no next_permutuation 
        //so before going into while loop we wil check once
        
        int temp=0;
        for(int i=0;i<pos.size();i++)
        for(int j=0;j<students[0].size();j++)
        if(students[i][j]==mentors[i][j])
            temp++;
        
        ans = max(ans, temp);
        
        
        
        //now do same thing unti you have permuations..
        while(next_permutation(pos.begin(),pos.end()))
        {
            int temp=0;
            for(int i=0;i<pos.size();i++)
            for(int j=0;j<students[0].size();j++)
            if(students[i][j]==mentors[pos[i]][j])
            temp++;
            
            ans=max(ans,temp);
        }
        return ans;

    }
};