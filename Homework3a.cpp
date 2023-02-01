// This program imports a graph from a file and finds the MST using Prim's algorithm.

#include <iostream>
#include <vector>
#include <cmath>
#include<fstream>
#include <cstdlib>
#include <sstream>
using namespace std;

class Edge {
    public:
        int n1, n2;  // node 1 and node 2 for the edge
        double d;  // distance between the 2 nodes
        Edge(int n1 = 0, int n2 = 0, double d = 0.0, bool c = false): n1(n1),n2(n2),d(d) {}  // constructor
        void getDistance(double min, double max) {  // assign a random distance value between min and max
            d = ((double((rand())) / RAND_MAX) * (max - min)) + min;
        }
};

class Graph {
    public:
        vector<Edge> edgeList;  // keep track of which edges are included in the graph
        void addEdge(Edge e) {edgeList.push_back(e);}  // add the edge to the list
        int importGraph(string fileName);  // get number of nodes and edge list for graph from "data.txt" file
};

// get number of nodes and edge list for graph from "data.txt" file
int Graph::importGraph(string fileName) {
    ifstream data(fileName);
    vector<string> edgeData;
    int nodes = 0;
    int i = 0;

    // read the data from the "data.txt" file line by line
    while(!data.eof()) {
        string line;
        getline(data, line);
        if (i == 0) {  // first line of file only contains the total node count value for the graph
            nodes = stoi(line);
        }
        else {  // get edge nodes and distance values as a string for each edge
            edgeData.push_back(line);
        }
        i++;
    }

    // extract the node and distance values of each edge as int/double data types
    for (string str: edgeData) {
        //cout << str << endl;
        Edge currentEdge;
        stringstream ss(str);
        int found;
        int j = 0;
        while (ss >> found) {
            switch (j) {
            case 0:  // first number of each string is always node #1
                currentEdge.n1 = found;
                break;
            case 1:  // second number of each string is always node #2
                currentEdge.n2 = found;
                break;
            case 2:  // third number of each string is always distance
                currentEdge.d = (double)found;
                break;
            default:
                break;
            }
            j++;
        }
        addEdge(currentEdge);  // add edge data from file to the graph's edge list
    }

    // Return the number of graph nodes
    return nodes;
}

class ShortestPath {
    public:
        vector<Edge> MST;
        double pathLength;
        double primMST(Graph g, int nodeCount, int startNode);
};

double ShortestPath::primMST(Graph g, int nodeCount, int startNode) {
    vector<Edge> possiblePath;
    vector<int> nodesVisited;
    double possibleEdgeLength = 0.0, shortestEdgeLength = 0.0, pathLengthSoFar = 0.0;
    bool foundAllNodes = false, alreadyVisitFlag = false;
    int edgeCount = 0, nextNode = 0, curNode = startNode;  // current node needs to start at the starting node

    // Begin by printing out the header line for the edge list
    cout << "PRIM'S MST EDGE LIST:" << endl;
    while (!foundAllNodes) {
        // Collect all edges within the graph's edge list that contain the starting node
        for (int i = 0; i < g.edgeList.size(); i++) {
            if ((g.edgeList[i].n1 == curNode) || (g.edgeList[i].n2 == curNode)) {
                // Exclude nodes that have already been visited
                for (int j = 0; j < nodesVisited.size(); j++) {
                    if ((g.edgeList[i].n1 == nodesVisited[j]) || (g.edgeList[i].n2 == nodesVisited[j])) {
                        alreadyVisitFlag = true;
                    }
                }
                if (!alreadyVisitFlag) {
                    possiblePath.push_back(g.edgeList[i]);
                }
                alreadyVisitFlag = false;
            }
        }

        // Find the shortest distance among the possible edges and the next node to move to
        for (int i = 0; i < possiblePath.size(); i++) {
            if ((i == 0) || (possiblePath[i].d < possibleEdgeLength)) {
                shortestEdgeLength = possiblePath[i].d;
                // Set the next node to be the opposite end of the edge as the previous node
                if (possiblePath[i].n1 == curNode) {
                    nextNode = possiblePath[i].n2;
                }
                else {
                    nextNode = possiblePath[i].n1;
                }
                possibleEdgeLength = possiblePath[i].d;
            }
        }

        // If the possible path list is empty, trigger an error
        if (possiblePath[0].d == 0) {
            cout << "DID NOT FIND ANY POSSIBLE PATHS!" << endl << endl;
            continue;
        }

        // Print the data for the edge that was just added to the MST
        edgeCount++;
        cout << "EDGE # " << edgeCount << ": " << "N1 = " << curNode << ", N2 = " << nextNode << ", D = " << shortestEdgeLength << endl;

        // Keep a running total of the path lengths so far
        pathLengthSoFar += shortestEdgeLength;

        // Add current node to the list of nodes previously visited to avoid looping back to where we started
        nodesVisited.push_back(curNode);

        // Set the current node to be next node for rerunning the loop
        curNode = nextNode;

        // Clear out variables for next loop iteration
        possiblePath.clear();

        // If all of the graph's nodes have been accounted for, stop the while loop
        if (nodesVisited.size() >= (nodeCount - 1)) {
            foundAllNodes = true;
        }
    }

    return pathLengthSoFar;
}

int main()
{
    string dataFile;
    int nodeCount = 0;
    double costMST = 0.0;
    Graph g;
    ShortestPath sp;

    // Get the graph's node count and edge data from a file
    dataFile = "graph.txt";
    nodeCount = g.importGraph(dataFile);

    // Find the graph's MST (minimum spanning tree) using Prim's algorithm, starting with the first edge's first node
    costMST = sp.primMST(g, nodeCount, g.edgeList[0].n1);
    cout << "MST COST = " << costMST << endl;

    return 0;
}