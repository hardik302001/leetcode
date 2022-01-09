    // My intuitions for those who have problem thinking, Why BINARY SEARCH worked here?
    // what I thought after reading the ques was,
    // more the days pass, more the flowers will be bloomed, and more flowers we have more bouquets we can make
    // like at the max day all flowers will be bloomed we will be able to make max number of bouquets

    // So we can binary search for days, like first check for mid of min and max day, if we can make bouquets then we              should try for less day, i.e. decreasing upper bound
    // else if we can't make specified count of bouquets then increase the day count as we will have more flowers now, so we may can satisfy the conditions, i.e. increase lower bound
    // so it looks like a binary search problem


class Solution {
public:
    
    // function to check if at given day, we can make atleast m bouquets using k consecutive flowers
    bool check(vector<int>&arr, int day, int k, int m){
      int count = 0; // to count bouquets we can make
      int size = 0; // keep track to no. of consecutive flowers
                    // as size == k, we make a bouquet using them

      for(int i=0; i<arr.size(); ++i){
        // if bloom day > curr day, then flower is not bloomed
        // it is the break point of consecutive flowers counting
        // we have to start again counting the flowers from next flower onward
        if(arr[i] > day) size = 0;
        else size++; // else flower is bloomed count it

        if(size == k){ // we have k consecutive flowers, make a bouquet 
          count++;
          size = 0;
        }
      }
      // can we make atleat m bouquets or not
      return count >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
      // is number of flowers we require is less then, we can't make 
      if(bloomDay.size() < m*k) return -1;

      int l = bloomDay[0], r = bloomDay[1];
      // min can be min day for blooming of atleast one flower
      // max days is when all flowers are bloomed
      for(auto &i: bloomDay){
        l = min(l, i);
        r = max(r, i);
      }

      while(l < r){
        int mid = l  + (r-l)/2;
        // if we can make m bouquets int mid days, try for less days
        if(check(bloomDay, mid, k, m)) r = mid;
        // we were not able to make, so we need more flowers, so increase days
        else l = mid+1;
      }
      return l;
    }
    
    
};