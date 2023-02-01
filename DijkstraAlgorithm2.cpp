#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

vector<vector<pair<int, int>>> graph;

void Dijkstra(int start, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first, current = pq.top().second;
        pq.pop();

        if (dist[current] < cost) continue;

        for (auto neighbor : graph[current]) {
            int to = neighbor.first, weight = neighbor.second;
            if (cost + weight < dist[to]) {
                dist[to] = cost + weight;
                pq.push({dist[to], to});
            }
        }
    }
}

int main() {
    int num_nodes = 5, num_edges = 7, start = 0;
    graph.resize(num_nodes);
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 5});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 2});
    graph[2].push_back({3, 3});
    graph[3].push_back({4, 2});
    graph[4].push_back({1, 4});

    vector<int> dist(num_nodes, INF);
    Dijkstra(start, dist);

    for (int i = 0; i < num_nodes; i++) {
        cout << "The shortest distance from node " << start << " to node " << i << " is: " << dist[i] << endl;
    }

    return 0;
}
