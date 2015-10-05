/*
 * dijkstra sample code
 *
 */

/* sampe input
 * 9       
 * 0 4 0 0 0 0 0 8 0
 * 4 0 8 0 0 0 0 11 0
 * 0 8 0 7 0 4 0 0 2
 * 0 0 7 0 9 14 0 0 0
 * 0 0 0 9 0 10 0 0 0
 * 0 0 4 0 10 0 2 0 0
 * 0 0 0 14 0 2 0 1 6
 * 8 11 0 0 0 0 1 0 7
 * 0 0 2 0 0 0 6 7 0
 */

/* sample output
 * 0 : 0
 * 1 : 4
 * 2 : 12
 * 3 : 19
 * 4 : 21
 * 5 : 11
 * 6 : 9
 * 7 : 8
 * 8 : 14
 */
#include "include/include.h"

using namespace std;

class Dijkstra {
private:
    int V; // number of vertexes and edges
    vector<vector<int> > edges; // edges and weight
    int *dist; // distance of each node

    bool *v_set; // the set of all unvisited nodes
    int extract_min() {
        int min_dist = INT_MAX;
        int min_index = 0;
        for (int i=0; i<V; i++) {
            if (!v_set[i] && dist[i] < min_dist) {
                min_dist = dist[i];
                min_index = i;
            }
        }
        return min_index;
    }
public:
    Dijkstra(int v, vector<vector<int> > &graph) : V(v) {
        dist = new int[v];
        v_set = new bool[v];
        for (int i=0; i<v; i++) {
            vector<int> tmp;
            for (int j=0; j<v; j++)
                tmp.push_back(graph[i][j]);
            edges.push_back(tmp);
            dist[i] = INT_MAX;
            v_set[i] = false;
        }
    };

    void execute(int source) {
        // initialize source
        dist[source] = 0;
        for (int counter = 0; counter < V; counter++) {
            int u = extract_min();
            v_set[u] = true;

            for (int v=0; v<V; v++) {
                if (edges[u][v] && !v_set[v]) {
                    int alt = dist[u] + edges[u][v];
                    if (alt < dist[v]) {
                        dist[v] = alt;
                    }
                }
            }
        }
    }

    void printDist() {
        for (int i=0; i<V; i++)
            cout << i << " : " << dist[i] << endl;;
    }

};

int main() {
    int v;
    cin >> v;

    // initialize graph to set all weight to 0
    vector<vector<int> > graph(v, vector<int>(v));
    // read each edges' weight
    for (int i=0; i<v; i++) {
        for (int j=0; j<v; j++) {
            int w;
            cin >> w;
            graph[i][j] = w;
        }
    }

    Dijkstra d(v, graph);
    d.execute(0);
    d.printDist();

    return 0;
}
