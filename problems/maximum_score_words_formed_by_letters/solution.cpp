class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char , int>sc;
        for(auto it: letters){
            sc[it]++;
        }
        int ans = recur(0 , words, score , sc);

        return ans;
    }
    
    int recur(int ind , vector<string>& words, vector<int>& score, unordered_map<char , int>&sc){
        if(ind>=words.size()){
            return 0;
        }

        
        int ignore = recur(ind+1 , words , score , sc);
        int consider = 0;
        int f = 0;
        unordered_map<char , int>temp;
        for(int i = 0 ;i<words[ind].size();i++){
            temp[words[ind][i]]++;
            if(temp[words[ind][i]] > sc[words[ind][i]]){
                f = 1;
                break;
            }
        }
        

        if(f==0){
            int cur = 0;
            for(int i = 0 ;i<words[ind].size();i++){
                sc[words[ind][i]]-= 1;
                cur += score[words[ind][i] - 'a'];
            }
            
            
            consider = cur + recur(ind+1 , words , score , sc);
            
            // backtracking
            for(int i = 0 ;i<words[ind].size();i++){
                sc[words[ind][i]]+= 1;    
            }      
        }
        
        return max(ignore,consider);
        
    }
};