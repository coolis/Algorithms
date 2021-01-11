#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

void topological_sort(etnordered_map<int, unordered_set<int> > &graph, unordered_set<int> &visited, stack<int> &reversed_order, int current_node) {
    if (visited.find(current_node) != visited.end()) {
        // this node is already visited.
        return;
    }   
    visited.insert(current_node);

    for (auto const &child_node : graph[current_node]) {
        topological_sort(graph, visited, reversed_order, child_node);
    }   

    reversed_order.push(current_node);
}

bool check_cycle(unordered_map<int, unordered_set<int> > &graph, stack<int> reversed_order) {
    unordered_map<int, int> positions;
    int index = 0;
    while (!reversed_order.empty()) {
        positions[reversed_order.top()] = index++;
        reversed_order.pop();
    }   
    for (auto const &pair : graph) {
        for (auto const &child : pair.second) {
            if (positions[pair.first] > positions[child]) {
                return true;
            }   
        }   
    }   
    return false;
}

bool topological_sort_bfs(unordered_map<int, unordered_set<int> > &graph, vector<int> &order) {
    unordered_map<int, int> indegrees;
    for (auto const &pair : graph) {
        indegrees[pair.first] = 0;
    }   
    for (auto const &pair : graph) {
        for (auto const &child : pair.second) {
            indegrees[child]++;
        }   
    }   

    queue<int> no_incoming_edges_node;
    for (int i = 0; i < indegrees.size(); i++) {
        if (indegrees[i] == 0) {
            no_incoming_edges_node.push(i);
        }   
    }   

    while (!no_incoming_edges_node.empty()) {
        int current_node = no_incoming_edges_node.front();
        order.push_back(current_node);
        no_incoming_edges_node.pop();
        for (auto const& node : graph[current_node]) {
            indegrees[node]--;
            if (indegrees[node] == 0) {
                no_incoming_edges_node.push(node);
            }   
        }   
    }   

    if (indegrees.size() != order.size()) {
        return false; 
    }   

    return true;
}

int main() {
    int n;
    cin >> n;
    unordered_map<int, unordered_set<int> > graph;
    for (int i=0; i<n; i++) {
        int x, y;
        std::cin >> x >> y;
        graph[x].insert(y);
    }   

    vector<int> order;
    if (!topological_sort_bfs(graph, order)) {
        cout << "There is a cycle in the graph!" << endl;
    }   
    for (int i=0; i<order.size(); i++) {
        cout << order[i] << " ";
    }   
    cout << endl;

    unordered_set<int> visited;
    stack<int> reversed_order;

    for (auto const &pair: graph) {
        topological_sort_dfs(graph, visited, reversed_order, pair.first);
    }   

    if (check_cycle(graph, reversed_order)) {
        cout << "There is a cycle in the graph!" << endl;
        return 0;
    }

    while (!reversed_order.empty()) {
        cout << reversed_order.top() << " ";
        reversed_order.pop();
    }
    cout << endl;

    return 0;
}
