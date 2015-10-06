#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;

void dfs(unordered_map<int, unordered_set<int> > &edges, int i, unordered_set<int> &visited) {
    visited.insert(i);
    for (auto it=edges[i].begin(); it!=edges[i].end(); it++) {
        if (visited.find(*it) == visited.end()) {
            dfs(edges, *it, visited);
        }
    } 
}

int main() {
    unordered_map<int, unordered_set<int> > edges;
    edges[0].insert(1);
    edges[0].insert(2);
    edges[1].insert(3);
    edges[2].insert(4);

    unordered_set<int> visited;
    dfs(edges, 0, visited);

    return 0;
}
