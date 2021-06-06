class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        //first is the integer string of firstWord, second for SecondWord 
        string first,second,target;
        /// converting first string to it's integer counterpart
        for(auto child:firstWord){
            int val=child-'a';
            string temp=to_string(val);
            first+=temp;
        }
        /// converting second string to it's integer counterpart
        for(auto child:secondWord){
            int val=child-'a';
            string temp=to_string(val);
            second+=temp;
        }
        /// converting third string to it's integer counterpart
            for(auto child:targetWord){
            int val=child-'a';
            string temp=to_string(val);
            target+=temp;
        }
       /// converting strings to integer using stoi function
        int first_integer=stoi(first);
        int second_integer=stoi(second);
        int target_integer=stoi(target);
        
        return ((first_integer+second_integer)==target_integer);
    }
};