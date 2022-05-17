class Solution
{
    public:
        vector<int> getRow(int n)
        {
            vector<int> prev = { 1 };
            for (int i = 1; i <= n; i++)
            {
                vector<int> temp;
                temp.push_back(1);
                for (int x = 1; x < prev.size(); x++)
                {
                    temp.push_back(prev[x] + prev[x - 1]);
                }
                temp.push_back(1);
                prev = temp;
            }

            return prev;
        }
};