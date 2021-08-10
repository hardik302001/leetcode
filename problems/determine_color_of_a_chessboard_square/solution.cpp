class Solution {
public:
    bool squareIsWhite(string crd) {
        int a = (crd[0] - 'a');
        int b = (crd[1] - '1');
        return (a+b)%2;
    }
};