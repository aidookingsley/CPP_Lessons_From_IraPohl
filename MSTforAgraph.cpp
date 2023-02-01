#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// Class to represent a graph
class Graph
{
public:
    int num_nodes;
    vector<pair<int, pair<int, int>>> edges;

    // Constructor to read in a graph from a file
    Graph(string file_name)
    {
        ifstream file(file_name);
        int i, j, cost;

        // Read in the number of nodes
        file >> num_nodes;

        // Read in the edges and their costs
        while (file >> i >> j >> cost)
        {
            edges.push_back({cost, {i, j}});
        }

        // Sort the edges by cost
        sort(edges.begin(), edges.end());
    }

    // Function to compute the minimum spanning tree using Kruskal's algorithm
    void KruskalMST()
    {
        int cost, i, j;
        vector<int> parent(num_nodes);

        // Initialize the parents of all nodes to be themselves
        for (int i = 0; i < num_nodes; i++)
            parent[i] = i;

        // Iterate through the edges
        for (auto edge : edges)
        {
            cost = edge.first;
            i = edge.second.first;
            j = edge.second.second;

            // Find the root of the nodes that the edge connects
            int a = find(i, parent);
            int b = find(j, parent);

            // If the nodes are not in the same set, add the edge to the minimum spanning tree
            if (a != b)
            {
                cout << "Edge " << i << "-" << j << " with cost " << cost << " included in MST" << endl;
                parent[a] = b;
            }
        }
    }

private:
    // Helper function to find the root of a node
    int find(int i, vector<int> &parent)
    {
        if (parent[i] == i)
            return i;
        return find(parent[i], parent);
    }
};

int main()
{
    Graph g("graph.txt");
    g.KruskalMST();
    return 0;
}
