#include<iostream>
#include<vector>

using namespace std;

template <class T>
class Queue {
public:
    Queue(int s) : size(s), front(0), count(0) {
        contents.reserve(size);
    }

    void push(T v) {
        if (count == size) return;
        contents[(front+count)%size] = v;
        count++;
    }

    void pop() {
        if (count == 0) return;
        front = (front+1)%size;
        count--;
    }

    T front() {
        return contents[front];
    }

private:
    vector<T> contents;
    int size, front, count;
};

int main() {

    Queue<int> queue(4);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);

    cout << queue.front() << endl;

    queue.pop();
    queue.push(5);
    cout << queue.front() << endl;


    return 0;    
}
