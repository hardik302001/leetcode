class Solution {
public:
    int minOperations(int n) {
      int x = 1, y = 1;
      if(n <= 0) return 0;  
      if(n == 1) return 1;
      while(x * 2 < n) x *= 2;
      y = x * 2 - n;  // 2 * x >n 
      x = n - x;          
      int add = minOperations(x);
      int subtract = minOperations(y);
      return 1 + min(add, subtract);
    }
};