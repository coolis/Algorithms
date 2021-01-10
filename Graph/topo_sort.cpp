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

int main() {
    int n;
    cin >> n;
    unordered_map<int, unordered_set<int> > graph;
    for (int i=0; i<n; i++) {
        int x, y;
        std::cin >> x >> y;
        graph[x].insert(y);
    }   

    unordered_set<int> visited;
    stack<int> reversed_order;

    for (auto const &pair: graph) {
        topological_sort(graph, visited, reversed_order, pair.first);
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
