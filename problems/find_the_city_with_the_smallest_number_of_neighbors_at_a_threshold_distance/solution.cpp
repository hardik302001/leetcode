// djisktra + brute force

// First, we need to make the adjacency list for the graph which contains for each city the city to which it is connected, and the edge weight of that edge.
// Now, we have to run Dijkstra’s algorithm for each city to find the distance of all other cities to it.
// Now, for each city, we have to calculate the reachable cities within the threshold. We can use the vector of pairs for the same, where the 1st element denotes the number of reachable cities to a particular city and the 2nd element represents the number of that city (that is used to break the tie).
// Sort the vector of pairs in a way that the 1st element of the vector will contain the desired output, and the second of the 1st element is the required city number.


/*
class Solution {
public:

    vector<pair<int,int>> adj[105];
    vector<pair<int,int>> ans;

    bool static cmp(const pair<int,int> p1 ,const pair<int,int> p2)
    {
        if(p1.first != p2.first)
            return p1.first < p2.first;

        return p1.second > p2.second;
    }

    void dijkstra(int src, int n, int distanceThreshold)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> distance(n + 1, INT_MAX);

        distance[src] = 0;
        pq.push({0,src});

        while(! pq.empty())
        {
            int prev = pq.top().second;
            int prevDist = pq.top().first;
            pq.pop();

            for(auto it : adj[prev])
            {
                int next = it.first;
                int nextDist = it.second;
                if(distance[next] > distance[prev] + nextDist)
                {
                    distance[next] = distance[prev] + nextDist;
                    pq.push({distance[next], next});
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(i != src && distance[i] <= distanceThreshold)
                cnt++;
        }

        ans.push_back({cnt,src});

    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];   
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        for(int i=0;i<n;i++)
        {
            dijkstra(i, n, distanceThreshold);
        }

        sort(ans.begin(),ans.end(),cmp);

        return ans[0].second;
    
    }
};

*/


// TC = O(n^3)
// floyd warshall
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector(n, 10001));
        int res = 0, smallest = n;
        for (auto& e : edges)
            dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];
        for (int i = 0; i < n; ++i)
            dis[i][i] = 0;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; ++j)
                if (dis[i][j] <= distanceThreshold)
                    ++count;
            if (count <= smallest) {
                res = i;
                smallest = count;
            }
        }
        return res;
    }
};