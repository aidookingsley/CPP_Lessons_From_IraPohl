// Code that generates a set of random undirected graphs
// and calculates de average path size between nodes using
// Dijkstra's algritm
// 18/01/2023

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <functional>
#include <random>
#include <limits>
#include <algorithm>

using namespace std;

const double RAND_RANGE_LOWER = 1.0;
const double RAND_RANGE_HIGHER = 10.0;
const int GRAPH_SIZE = 50;
const int MC_SIMUL_SAMPLES = 100;
double INF = numeric_limits<double>::infinity();

default_random_engine generator;
uniform_real_distribution<double> prob_dist(0.0, 1.0);
uniform_real_distribution<double> distance_dist(RAND_RANGE_LOWER, RAND_RANGE_HIGHER);

// -------------------- Graph class -------------------------
class Graph
{
public:
    Graph(vector<vector<double>> adj_mat) : adj_mat(adj_mat){};

    // Get adjacency matrix
    vector<vector<double>> get_adj_mat()
    {
        return adj_mat;
    }

    // Return number of vertices
    int V()
    {
        return v;
    }

    // Return number of edges
    int E()
    {
        return e;
    }

    // Check if exists an edge between x and y
    bool adjacent(int x, int y)
    {
        return adj_mat[x][y];
    }

    // Return neighbours of a node
    list<int> neighbours(int x)
    {
        list<int> neigh;
        int rows = adj_mat.size();
        int cols = adj_mat[0].size();
        for (int i = 0; i < rows; i++)
        {
            if (adj_mat[x][i] != 0)  // adj_mat[i][j] != 0 means that exists an edge (i,j)
            {
                neigh.push_back(i);
            }
        }
        return neigh;
    }

    // Add edge to graph
    void add_edge(int x, int y, double d)
    {
        adj_mat[x][y] = d;
    }

    // Delete edge of graph
    void delete_edge(int x, int y)
    {
        adj_mat[x][y] = 0;
    }

    // Return edge distance
    double get_edge_value(int x, int y)
    {
        return adj_mat[x][y];
    }

    // Set edge distance
    void set_edge_value(int x, int y, int a)
    {
        adj_mat[x][y] = a;
        adj_mat[y][x] = a; // Graph is undirected
    }

private:
    vector<vector<double>> adj_mat; // Adjacency matrix
    int v = adj_mat.size();         // Number of vertices

    // To find graph edges, one can simply count the non-zero 
    // values in the lower triangular matrix of adj_mat
    int edges_of_graph(vector<vector<double>> adj_mat)
    {
        int sum = 0;
        int rows = adj_mat.size();
        int cols = adj_mat[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (adj_mat[i][j] != 0)
                {
                    sum += 1;
                }
            }
        }
        return sum;
    }
    int e = edges_of_graph(adj_mat); // Number of edges
};
// -----------------------------------------------------------

// Create random graph of v vertices
Graph random_graph(int v, double edge_density)
{
    vector<vector<double>> adj_mat(v, vector<double>(v)); // Defaults to zero initial value
    // Loop through lower triangular matrix as the graph is undirected
    // Diagonal elements are 0 because we are excluding loops of size 1
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < i; j++)
        {
            double prob = prob_dist(generator);
            if (prob <= edge_density)
            {
                adj_mat[i][j] = distance_dist(generator);
                adj_mat[j][i] = adj_mat[i][j];
            }
        }
    }
    Graph g(adj_mat);
    return g;
}

// ------------- Comparator for PriorityQueue ----------------------
// Pair of {vertex, value} comparator
inline bool pair_comparator(pair<int, double> p1, pair<int, double> p2)
{
    return p1.second < p2.second;
}
// -------------------------------------------------------------------

// --------------------- PriorityQueue Class -------------------------
class PriorityQueue
{
public:
    PriorityQueue(function<bool(pair<int, double>, pair<int, double>)> comparator = pair_comparator) : comparator(comparator){};

    // Change value of vertice v
    void chg_priority(int v, double new_value){

        for (int i = 0; i < size(); i++)
        {
            if (heap[i].first == v)
            {
                heap[i].second = new_value;
                heapify_up(i); // Corrects heap structure
            }
        }
    }

    void min_priority()
    {
        // Replace root of heap with last element and pops last element
        heap[0] = heap.back();
        heap.pop_back();
        // Correct heap structure by applying the function to the root
        heapify_down(0);
    }

    bool contains(int v)
    {
        for (auto &x : heap)
        {
            if(x.first == v){
                return true;
            }
        }
        return false;
    }

    void insert(pair<int, double> queue_elem)
    {
        heap.push_back(queue_elem);
        int i = size() - 1; // Last element
        heapify_up(i);      // Order in min heap structure
    }

    pair<int, double> top()
    {
        return heap[0];
    }

    int size()
    {
        return heap.size();
    }

    bool empty()
    {
        return size() == 0;
    }

    vector<pair<int, double>> get_heap()
    {
        return heap;
    }

private:
    vector<pair<int, double>> heap;
    // Comparator must be passed for complex data types, such pairs that were used
    function<bool(pair<int, double>, pair<int, double>)> comparator;
    // Parent of node i
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    // Left child of node i
    int left_child(int i)
    {
        return 2 * (i + 1) - 1;
    }
    // Right child of node i
    int right_child(int i)
    {
        return 2 * (i + 1);
    }
    // Heapify-down algoritm -> arranges data in the min heap structure
    void heapify_down(int i)
    {
        int left = left_child(i);
        int right = right_child(i);
        int smallest = i;

        // Look at heap[i], heap[left] and heap[right] to find smallest
        if (left < size() && comparator(heap[left], heap[i]))
        {   
            smallest = left;
        }
        if (right < size() && comparator(heap[right], heap[smallest]))
        {
            smallest = right;
        }
        // If smallest is not parent node, swap and call heapify again
        if (smallest != i)
        {   
            swap(heap[i], heap[smallest]);
            heapify_down(smallest);
        }
    }
    // Heapify-up algoritm -> arranges data in the min heap structure
    void heapify_up(int i)
    {
        // Check if node i and parent don't violate min heap condition
        // If that is true, then swap values and call the function again
        if (i && comparator(heap[i], heap[parent(i)]))
        {
            swap(heap[i], heap[parent(i)]);
            heapify_up(parent(i));
        }
    }
};
// ---------------------------------------------------------------

// ------------------ ShortestPath class -------------------------
class ShortestPath
{
public:
    ShortestPath(Graph G) : G(G){};

    list<int> vertices()
    {
        int V = G.V();
        list<int> vert(V);
        iota(vert.begin(), vert.end(), 0);
        return vert;
    }

    list<int> path(int source, int destiny)
    {
        // Shortest path
        vector<pair<int, double>> s_path = dijkstra_alg(source, destiny);
        list<int> node_path;
        // Goes from destiny to source in prev vector from dijkstra's alg 
        while(destiny != source){
            node_path.push_front(destiny);
            int prev = s_path[destiny].first;
            destiny = prev;
        }
        node_path.push_front(source);
        return node_path;
    }

    // s_path[destiny] is the distance from node1 to node2 (using node1 as source)
    double path_size(int source, int destiny)
    {
        vector<pair<int, double>> s_path = dijkstra_alg(source, destiny);
        return s_path[destiny].second;
    }

private:
    Graph G;

    // ------------ Dijkstra's algoritm --------------------
    vector<pair<int, double>> dijkstra_alg(int source, int destiny)
    {
        vector<double> dist(G.V());
        vector<int> prev(G.V());
        vector<int> open_set;
        PriorityQueue pq;
        // Initialize distances
        dist[source] = 0;
        for (int i = 0; i < G.V(); i++)
        {   
            if(i != source){
                dist[i] = INF; // Distances initialized to infinity
            }
            prev[i] = -1;  // Predecessor of source initialized to undefined (-1)
            pq.insert({i, dist[i]});
        }

        // Loop through priority queue finding best vertices
        while(!pq.empty())
        {
            int least_cost_vert = pq.top().first; // Return best vertice
            pq.min_priority(); // Remove best vertice from queue
            open_set.push_back(least_cost_vert); // Add vertice from priority queue to open set
            if (find(open_set.begin(), open_set.end(), destiny) != open_set.end()){
                break; // Destiny is in open set    
            }
            list<int> neighbours = G.neighbours(least_cost_vert);
            for (const auto &x : neighbours)
            {   
                if(pq.contains(x)){
                    double curr_dist = dist[least_cost_vert] + G.get_edge_value(least_cost_vert, x); // Current distance
                    // Check if is least then previous distances
                    if(curr_dist < dist[x]){
                        dist[x] = curr_dist;
                        pq.chg_priority(x, curr_dist); // Update value in priority_queue
                        prev[x] = least_cost_vert;
                    }
                }
            }
        }
        vector<pair<int, double>> ret_pair(prev.size());
        // Create pair from prev and dist 
        for (unsigned i = 0; i < prev.size(); i++){
            ret_pair[i] = make_pair(prev[i], dist[i]);
        }

        return ret_pair;
    }
    // -------------------------------------------------------
};
// ---------------------------------------------------------------

// --------------- MonteCarloSimulation class --------------------
class MonteCarloSimulation{
    public:
        MonteCarloSimulation(int samples, double edge_density) : samples(samples), edge_density(edge_density){};

        double get_average_path(){
            return find_total_average_path();
        }

    private:
        int samples;
        double edge_density;
        // Find average path of one graph
        double find_sample_average_path(){
            Graph G = random_graph(GRAPH_SIZE, edge_density);
            ShortestPath s_path(G);
            double total_dist = 0.0;
            double dist = 0.0;
            int not_connected_nodes = 0;
            for (int i = 1; i < GRAPH_SIZE; i++)
            {
                dist = s_path.path_size(0, i);
                if (dist != INF){
                    total_dist += dist; // Find path size between node 0 and every other node
                }else{
                    not_connected_nodes++;
                }
            }
            return total_dist / (GRAPH_SIZE - not_connected_nodes);
        }
        // Find average path of 'samples' graphs
        double find_total_average_path(){
            double total_dist = 0.0;
            for (int i = 0; i < samples; i++)
            {
                total_dist += find_sample_average_path();
            }
            return total_dist / samples;
        }
};
// ---------------------------------------------------------------

// ------------- Operator overload -----------------------
// Print list
template <class LIST_ELEM>
ostream &operator<<(ostream &out, list<LIST_ELEM> const &list)
{
    for (auto const &i : list)
    {
        out << i << "\n";
    }
    return out;
}

// Print graph
ostream &operator<<(ostream &out, Graph &graph)
{
    vector<vector<double>> adj_mat = graph.get_adj_mat();
    int rows = adj_mat.size();
    int cols = adj_mat[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            out << adj_mat[i][j] << "\t";
        }
        out << "\n";
    }
    return out;
}

// Print PriorityQueue
ostream &operator<<(ostream &out, PriorityQueue &pq)
{
    vector<pair<int, double>> heap = pq.get_heap();
    for (const auto &x : heap)
    {
        out << x.first << ": " << x.second << "\n";
    }
    out << "\n";
    return out;
}
// -------------------------------------------------------

int main(void)
{
    MonteCarloSimulation mcs_20(MC_SIMUL_SAMPLES, 0.2);
    MonteCarloSimulation mcs_40(MC_SIMUL_SAMPLES, 0.4);
    cout << "Edge Density: 20%\n";
    cout << "Graph Samples: " << MC_SIMUL_SAMPLES << ".\n";
    cout << "Average Path: " << mcs_20.get_average_path() << "\n\n";
    cout << "Edge Density: 40%\n";
    cout << "Graph Samples: " << MC_SIMUL_SAMPLES << ".\n";
    cout << "Average Path: " << mcs_40.get_average_path() << endl;
    return 0;
}
/*
-> 200 words:

In this assignment I have learned about the Priority Queue structure, which I was not familiar with.
Also, I could practice the concept of creating and initializing classes. 
Despite a lot of time invested, I really appreciated debugging some errors, because I could learn more about the language and find new ways to do things.

-> Output of program:

Edge Density: 20%
Graph Samples: 100
Average Path: 6.81972

Edge Density: 40%
Graph Samples: 100
Average Path: 4.5571
*/