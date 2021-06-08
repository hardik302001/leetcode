class StockSpanner {
    stack<pair<int, int>> st; // [price, days]

    public:
        StockSpanner() {}

        int next(int price) {
            int days = 1;
            while(st.size() && price >= st.top().first)
            {
                int x =  st.top().second;  //span of previous stock
                days = days + x;
                st.pop();
            }
            cout<<days<<" ";
            st.push({price, days});
            return days;
            
        }
};