#include<iostream>

using namespace std;

template <typename T>
struct Node {
    T v;
    Node<T> *pre;
    Node(T t) : v(t), pre(NULL) {} 
};

template <class T>
class Stack {
public:
    Stack() {
        back = new Node<T>(NULL);
    }

    void push(T v) {
        Node<T> *newNode = new Node<T>(v);
        newNode->pre = back;
        back = newNode;
    } 

    T top() {
        return back->v; 
    }

    void pop() {
        if (back->pre) {
            Node<T> *tmp = back;
            back = back->pre;
            free(tmp);
        }
    }

private:
    Node<T> *back;
};


int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    s.pop();
    s.pop();
    cout << s.top() << endl;
    return 0;
}
