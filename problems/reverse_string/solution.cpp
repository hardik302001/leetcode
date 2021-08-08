class Solution {
public:
    void check(int beg, int end, vector<char>&s){
        if(beg>=end){
            return;
        }
        swap(s[beg],s[end]);
        beg++;
        end--;
        
        check(beg, end, s);
    }
    
    
    void reverseString(vector<char>& s) {
        int n = s.size();
        check(0,n-1,s);
    }
};