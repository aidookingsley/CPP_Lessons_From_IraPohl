#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

const int INF = 1e9;

class Edge
{
public:
    int to, weight;
    Edge(int to, int weight) : to(to), weight(weight) {} //default constructor
};

vector<vector<Edge>> graph;

void dijkstra(int start, vector<int> &distances)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    distances[start] = 0;

    while (!pq.empty())
    {
        int cost = pq.top().first, current = pq.top().second;
        pq.pop();

        if (distances[current] < cost)
            continue;

        for (auto edge : graph[current])
        {
            int to = edge.to, weight = edge.weight;
            if (cost + weight < distances[to])
            {
                distances[to] = cost + weight;
                pq.push({distances[to], to});
            }
        }
    }
}

double average_shortest_path(int num_samples)
{
    double total_distance = 0;
    for (int i = 0; i < num_samples; i++)
    {
        int start = rand() % graph.size();
        int end = rand() % graph.size();
        vector<int> distances(graph.size(), INF);
        dijkstra(start, distances);
        total_distance += distances[end];
    }
    return total_distance / num_samples;
}

void generate_graph(int num_nodes, int num_edges)
{
    graph.resize(num_nodes);
    for (int i = 0; i < num_edges; i++)
    {
        int a = rand() % num_nodes, b = rand() % num_nodes;
        int weight = rand() % 100;
        graph[a].push_back(Edge(b, weight));
        graph[b].push_back(Edge(a, weight));
    }
}

int main()
{
    srand(time(0));
    int num_nodes = 50, num_edges = 100, num_samples = 100;
    generate_graph(num_nodes, num_edges);
    double avg_shortest_path = average_shortest_path(num_samples);
    cout << "The average shortest path is: " << avg_shortest_path << endl;
    return 0;
}
