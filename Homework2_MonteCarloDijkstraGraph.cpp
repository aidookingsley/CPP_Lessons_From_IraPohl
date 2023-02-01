// Code that generates a set of random undirected 
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
    int to;
    double weight;
    Edge(int to, double weight) : to(to), weight(weight) {}
    // default constructor
};

class Graph
{
public:
    int num_nodes;
    double density;
    vector<vector<Edge>> edges;
    Graph(int num_nodes, double density) : num_nodes(num_nodes), density(density) { edges.resize(num_nodes); }

    // function to add edges to the nodes
    void add_edge(int from, int to, double weight)
    {
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }

    // function to generate graph with random set of edges with positive distance
    void generate_graph()
    {
        for (int i = 0; i < num_nodes; ++i)
        {
            for (int j = i + 1; j < num_nodes; ++j)
            {
                if (rand() < density * RAND_MAX)
                {
                    double weight = 1.0 + rand() / (RAND_MAX / (10.0 - 1.0));
                    add_edge(i, j, weight);
                }
            }
        }
    }
    void dijkstra(int start, vector<double>& dist){
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push({0, start});
        dist[start] = 0;

        while(!pq.empty()){
            double cost = pq.top().first;
            int current = pq.top().second;
            pq.pop();

            if (dist[current]<cost) continue;

            for (auto edge : edges[current]){
                int to = edge.to;
                double weight = edge.weight;
                if (cost + weight < dist[to]){
                    dist[to] = cost + weight;
                    pq.push({dist[to], to});
                }
            }
        }
    }
};

double average_shortest_path(Graph& graph, int num_samples){
    double total_distance = 0;
    for (int i = 0; i < num_samples; ++i){
        int start = 0;
        vector<double> dist(graph.num_nodes, INF);
        graph.dijkstra(start, dist);
        for (int j = start + 1; j < graph.num_nodes; ++j){
            total_distance += dist[j];
        }
        
    }
    return total_distance / (num_samples * (graph.num_nodes - 1));
}

int main(){
    srand(time(0));
    int num_nodes = 50, num_samples = 100;
    double density = 0.2;
    Graph graph(num_nodes, density);
    graph.generate_graph();
    double avg_path_length = average_shortest_path(graph, num_samples);
    cout << "The average shortest path length for density " << density << " is: " << avg_path_length << endl;

    density = 0.4;
    Graph graph2(num_nodes, density);
    graph2.generate_graph();
    avg_path_length = average_shortest_path(graph2, num_samples);
    cout << "The average shortest path length for density " << density << " is: " << avg_path_length << endl;
    return 0;
}