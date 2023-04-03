class Solution {
public:
    vector<int> ans;
    vector<int> splitIntoFibonacci(string S) {
        vector<int> x;
        fibonacciSeq(S, x, 0);
        return ans;
    }
    
    void fibonacciSeq(string S, vector<int> vec, int index) {
        if (index == S.length() && vec.size() > 2) {
            ans = vec;
            return;
        }
        long num = 0;
        for (int i = index; i < S.length(); i++) {
            num = num * 10 + S[i] - '0';
            if (num > INT_MAX) return;
            if (S[index] == '0' && i > index) return; // To handle the case of numbers like 1023, so in this case when are at index 1 and trying to form 02 or 023, it wouldnt allow to do that
            if (vec.size() < 2 || num == ((long)vec.back() + (long)vec[vec.size()-2])) {
                vec.push_back(num);
                fibonacciSeq(S, vec, i + 1);
                vec.pop_back();
            }
        }
    }
};