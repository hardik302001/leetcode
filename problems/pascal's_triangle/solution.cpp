class Solution
{
    public:
        vector<vector < int>> generate(int n)
        {
            vector<vector < int>> ans;
            vector<int> temp = { 1 };
            ans.push_back(temp);
            for (int i = 1; i < n; i++)
            {
                vector<int> temp;
                temp.push_back(1);
                for (int x = 1;x<ans.back().size(); x++)
                {
                    temp.push_back(ans.back()[x] + ans.back()[x - 1]);
                }
                temp.push_back(1);
                ans.push_back(temp);
            }
            
            return ans;
        }
};