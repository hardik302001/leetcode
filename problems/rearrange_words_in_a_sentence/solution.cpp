
//dont worry about secnd condition!!
//while sorting it will be automatically adjusted!

//well you need not acutually sort it ..taht would be O(nlogn), but here we are doing it in O(n)


class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);     ///first char lower

        stringstream ss(text);
        map<int, string> mp;
        string curr_word;
        while(ss>> curr_word){
            mp[curr_word.size()]+= curr_word + " ";
        }
        string res;
        for(const auto & e: mp){
            res += e.second;
        }
        res.pop_back();         //extra space char
        res[0] = toupper(res[0]);     //do firs char of sentence upper
        return res;
    }
};