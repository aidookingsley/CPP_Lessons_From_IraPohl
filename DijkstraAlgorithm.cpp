#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

void Dijkstra(int source, vector<vector<pair<int, int>>> &adjList, vector<int> &dist)
{
    int n = adjList.size();
    dist.assign(n, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto &[v, w] : adjList[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n = 4, m = 5;
    std::vector<std::vector<std::pair<int, int>>> adjList(n);
    adjList[0].push_back({1, 2});
    adjList[0].push_back({2, 5});
    adjList[1].push_back({2, 4});
    adjList[1].push_back({3, 6});
    adjList[2].push_back({3, 2});
    std::vector<int> dist;
    Dijkstra(0, adjList, dist);
    for (int i = 0; i < n; i++)
    {
        cout << "Distance from source to node " << i << ": " << dist[i] << endl;
    }
    return 0;
}
