#include<iostream>

using namespace std;

template <class T>
struct Node {
    T v;
    Node<T> *next;
    Node(T t) : v(t), next(NULL) {}
};

template <class T>
class Queue {
public:
    Queue() {
        start = new Node<T>(NULL);
        end = start;
    }

    void push(T v) {
        end->next = new Node<T>(v);
        end = end->next;
    }

    void pop() {
        Node<T>* tmp = start->next;
        if (tmp) {
            start->next = tmp->next;
            free(tmp);
        }
    }

    T front() {
        if (start->next)
            return start->next->v;
        else
            return NULL;
    }
private:
    Node<T> *start, *end;
};

int main() {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3); 
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;


    return 0;
}
