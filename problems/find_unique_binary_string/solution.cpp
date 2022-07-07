//time complexity of this approcah -> O(nlogn).
//Because in worst case we try n+1 different strings (because in order to find a string not present in the "nums" we compare the string formed with the strings in nums ie. "n") and "set.find" fuctions takes O(logn) time . 
//Therefore overall time complexity is O(nlogn).


// backtracking , all binary substrings  of size n
class Solution {
public:
    //findPossibleStrings
   void findPossibleStrings(int n, int currindex, set<string> &st, string s ,vector<string> &permu){
        //base case
        if(currindex==n){
            if(st.find(s)==st.end()){
                permu.push_back(s);
            }
            return;
        }
        
        //first adding 0 to the string
        findPossibleStrings(n,currindex+1,st,s+"0",permu);
        if(permu.size()!=0){
            return;
        }
       
        //then trying with adding 1 to the string
        findPossibleStrings(n,currindex+1,st,s+"1",permu);
        if(permu.size()!=0){
            return;
        }
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        //size of nums == size of nums[0];
        //therefore every position has two choices - either 1 or 0;
		
		//storing strings in nums in set 
        set<string>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        
        vector<string>permu;
        string s ="";
        int n = nums[0].size();
        findPossibleStrings(n,0,st,s,permu);
        return permu[0];
    }
};