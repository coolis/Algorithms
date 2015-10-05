#include<iostream>
#include<unordered_map>

using namespace std;

class GraphNode {
private:
    int value;
    GraphNode *next;
public:
    GraphNode(int v) : value(v), next(NULL) {};
    int getValue() {
        return value;
    }
    void setValue(int value) {
        this->value = value;
    }
    GraphNode *getNext() {
        return next;
    }
    void setNext(GraphNode *next) {
        this->next = next;
    }
};

// linked list representation
class Graph {
private:
    unordered_map<int, GraphNode*> list;
public:
    Graph() {}
    void addEdge(int A, int B) {
        GraphNode *tmp;
        tmp = new GraphNode(B);
        tmp->setNext(list[A]);
        list[A] = tmp; 
        tmp = new GraphNode(A);
        tmp->setNext(list[B]);
        list[B] = tmp;
    }
    unordered_map<int, GraphNode*> getList() {
        return list;
    }
};

int main() {
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    unordered_map<int, GraphNode*> list = g.getList();
    for (auto it=list.begin(); it!=list.end(); it++) {
        cout << it->first;
        GraphNode* tmp = it->second;
        while (tmp) {
            cout << "->" << tmp->getValue();
            tmp = tmp->getNext();
        }
        cout << endl;
    }

    return 0;
}
