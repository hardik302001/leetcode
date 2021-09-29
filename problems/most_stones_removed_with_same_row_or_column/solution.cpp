/*

Problem:
we can remove a stone if and only if,
there is another stone in the same column OR row.
We try to remove as many as stones as possible.


One sentence to solve:
Connected stones can be reduced to 1 stone,
the maximum stones can be removed = stones number - islands number.
so just count the number of "islands".


# Connected stones

Two stones are connected if they are in the same row or same col.
Connected stones will build a connected graph.
It's obvious that in one connected graph,
we can't remove all stones.

We have to have one stone left.
An intuition is that, in the best strategy, we can remove until 1 stone.

I guess you may reach this step when solving the problem.
But the important question is, how?


# A good strategy

In fact, the proof is really straightforward.
You probably apply a DFS, from one stone to next connected stone.
You can remove stones in reversed order.
In this way, all stones can be removed but the stone that you start your DFS.

One more step of explanation:
In the view of DFS, a graph is explored in the structure of a tree.
As we discussed previously,
a tree can be removed in topological order,
from leaves to root.


# Count the number of islands

We call a connected graph as an island.
One island must have at least one stone left.
The maximum stones can be removed = stones count  - islands count

The whole problem is transferred to:
What is the number of islands?

You can show all your skills on a DFS implementation,
and solve this problem as a normal one.

*/


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int res = 0;                 // number of connected islands
        int n = stones.size();
        vector<bool> visited(n, false);
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i]){
                dfs(stones, visited, i);
                res++;
            }
        }
        
        
        //but we need to return the maximum number of stones that can be removed, that will be total stones - island count
        
        return (n - res);
    }
    
    void dfs(vector<vector<int>>& stones, vector<bool>& visited, int curr)
    {
        if(visited[curr]) return ;
        visited[curr] = true;
        
        for(int i=0; i<stones.size(); i++)
        {
            if(!visited[i] && (stones[i][0] == stones[curr][0] || stones[curr][1] == stones[i][1]))
                dfs(stones, visited, i);
        }
    }
};