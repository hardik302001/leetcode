class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int> > updates)
    {
        vector<int> result(length, 0);

        for (auto& tuple : updates) {
            int start = tuple[0], end = tuple[1], val = tuple[2];

            result[start] += val;
            if (end < length - 1)
                result[end + 1] -= val;
        }

        // partial_sum applies the following operation (by default) for the parameters {x[0], x[n], y[0]}:
        // y[0] = x[0]
        // y[1] = y[0] + x[1]
        // y[2] = y[1] + x[2]
        // ...  ...  ...
        // y[n] = y[n-1] + x[n]

        partial_sum(result.begin(), result.end(), result.begin());

        return result;
    }
};