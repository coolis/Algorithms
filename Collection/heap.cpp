#include <vector>
#include <iostream>
using namespace std;

class Heap {
private:
    vector<int> _elements;

    void BubbleDown(int index) {
        int length = _elements.size();
        int left = 2*index+1;
        int right = 2*index+2;

        if (left >= length) return;

        int maxIndex = index;

        if (_elements[maxIndex] < _elements[left])
            maxIndex = left;
        if (right < length && _elements[maxIndex] < _elements[right])
            maxIndex = right;

        if (maxIndex != index) {
            swap(_elements[maxIndex], _elements[index]);
            BubbleDown(maxIndex);
        }
    }

    void BubbleUp(int index) {
        if (index == 0) return;
        int parent = (index - 1) / 2;

        int maxIndex = index;

        if (_elements[maxIndex] < _elements[parent])
            maxIndex = parent;

        if (maxIndex != index) {
            swap(_elements[maxIndex], _elements[index]);
            BubbleUp(maxIndex);
        }
    }
    
public:
    Heap(vector<int> v) : _elements(v) {
        int length = _elements.size();
        for (int i=length-1; i>=0; i--) {
            BubbleDown(i);
        }
    }

    Heap(int *a, int n) : _elements(a, a+n) {
        int length = _elements.size();
        for (int i=length-1; i>=0; i--) {
            BubbleDown(i);
        }
    }

    Heap() {}

    void push(int e) {
        _elements.push_back(e);
        BubbleUp(_elements.size()-1);
    }

    int top() {
        return _elements[0];
    }

    void pop() {
        if (_elements.empty()) return;
        swap(_elements.front(), _elements.back());
        _elements.pop_back();
        BubbleDown(0);
    }
};

int main() {
    int array[] = {10, 4, 5, 30, 3, 300};
    Heap heap(array, 6);
    heap.push(100);
    for (int i=0; i<6; i++) {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;
    return 0;
}
