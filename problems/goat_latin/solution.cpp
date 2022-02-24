class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
public:
    string toGoatLatin(string S) {
        string result;
        string append = "maa", w;
        istringstream line(S);
        while (line >> w) {
            if (!isVowel(w[0])) {
                w += w[0];         // Add the first charater to last
                w.erase(0, 1);     // Erase the first charater
            }
            w += append;           // Append maa, maaa, maaaa, ......
						
            result += w + " ";     // Add the word to result
            append += 'a';         // Prepare the next maaa, maaaa, maaaaa, ...
        }
        result.erase(result.size()-1, 1); // Don't forget to remove the whitespace at the end!
        return result;
    }
};