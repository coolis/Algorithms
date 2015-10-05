#include<iostream>

using namespace std;

template <class T>
class Queue {
public:
    Queue(int s) : size(s), start(0), count(0) {
        contents = new T[s];
    }

    void push(T v) {
        if (count == size) return;
        contents[(start+count)%size] = v;
        count++;
    }

    void pop() {
        if (count == 0) return;
        start = (start+1)%size;
        count--;
    }

    T front() {
        return contents[start];
    }

private:
    T *contents;
    int size, start, count;
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
