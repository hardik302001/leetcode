// https://leetcode.com/problems/daily-temperatures/submissions/


// pge
// we need to return at each step, so we have to calculate at every step and keep track !


class StockSpanner {
    stack<pair<int, int>> st; // [price, days]

    public:
        StockSpanner() {}

        int next(int price) {
            int days = 1;
            while(st.size() &&  st.top().first <= price )
            {
                int x =  st.top().second;  //span of previous stock
                days = days + x;
                st.pop();
            }
            // cout<<days<<" ";
            st.push({price, days});
            return days;
            
        }
};