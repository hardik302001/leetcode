//STACK
// NSE
/*

Here greedy approach is applied to solve the question.
We'll take the stack and a frequency vector and visited vector.
If the coming character is visted before then we'll just decrease its frequency and move on to next character in string.
We'll only fill stack in lexicographically order and when we encounter lexicographically low character then we start poping out the characters from the stack so that we can maintain lexicographical order but first we check the frequency of that character so that we can't miss that character in our ans.
And after traversing whole string we just pop out the charcters from stack and store in another string.
And before returning just reverse the string to get the desired ans.
        
*/




class Solution {
public:
    string removeDuplicateLetters(string text) {
        
        vector<bool> seen(26, false);          //to check if it is considered once
        vector<int> freq(26, 0);       

        for(char ch : text)
            freq[ch - 'a']++;

        stack<char> st;

        for(int i=0; i<text.size(); i++){
            char ch = text[i];

            freq[ch - 'a']--;
            if(seen[ch - 'a'])         //if it is already considered, then move on
                continue;

            while(st.size() != 0 && st.top() > ch && freq[st.top() - 'a'] > 0){  // if we get lexographically smaller char, and the freq of st.top() > 0, if means we can get the char st.top(), again while traversing the string, so we will consider it that time... so we pop , until this is possible, to get as smallest possible lexograph as we can!
                seen[st.top() - 'a'] = false;         // we mark its seen as false and pop it 
                st.pop();
            }
            seen[ch - 'a'] = true;
            st.push(ch);
            
        }

        string ans = "";
        while(st.size() != 0){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
