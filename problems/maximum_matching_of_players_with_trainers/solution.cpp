class Solution 
{
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int count=0;
        int s1=0, s2=0;
        
        while(s1<players.size() && s2<trainers.size())
        {
            if(players[s1] <= trainers[s2])
            {
                count++;
                s1++;
                s2++;
            }
            
            else if(players[s1] > trainers[s2])
            {
                s2++;
            }
        }
        return count;
        
    }
};