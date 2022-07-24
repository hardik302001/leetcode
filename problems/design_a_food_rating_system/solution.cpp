class myComparator {
  public:
    bool operator() (pair<int,string> &p1, pair<int,string> &p2) {   // highest rate, smallest food string
      if(p1.first == p2.first) return p1.second > p2.second;
      
      return p1.first < p2.first;
    }
};



class FoodRatings {
public:
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,myComparator>>mp;  // cui: rate, food
    unordered_map<string,int>rate;     // food: rate   , to avoid tle(bcz if u update rate by popping from pq and adding updated rate, you get tle)
    unordered_map<string,string>cuis;  // food: cui
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
        int n = foods.size();
        for(int i = 0; i < n; i++)
        {
            mp[cuisines[i]].push({ratings[i],foods[i]});
            cuis[foods[i]] = cuisines[i];
            rate[foods[i]] = ratings[i];
        }
        
    }
    
    void changeRating(string food, int newRating)
    {
        rate[food] = newRating;              // to keep track of updated rate
        string cuisine = cuis[food];
        mp[cuisine].push({newRating,food});  // we make another copy, of updated rate
    }
    
    string highestRated(string cuisine) 
    {
        while(true)
        {
            auto it = mp[cuisine].top();
            if(rate[it.second] == it.first) return it.second;
            else mp[cuisine].pop();                              // remove copy
        }
        
    }
};