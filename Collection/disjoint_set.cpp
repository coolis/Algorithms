#include<iostream>

using namespace std;

class Disjoint_Set {
private:
    int N;
    int *parent;
    int *rank;

public:
    Disjoint_Set(int n) : N(n) {
        parent = new int[n];
        rank = new int[n];
        for (int i=0; i<n; i++) {
            parent[i] = -1;
            rank[i] = 0;
        }
    }

    void MakeSet(int x) {
        parent[x] = x;
    }

    int Find(int x) {
        if (parent[x] == -1)
            return -1;
        else if (parent[x] == x)
            return x;
        else
            return Find(parent[x]);
    }

    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

int main() {
    Disjoint_Set ds(5);
    
    ds.MakeSet(1);
    ds.MakeSet(2);
    ds.MakeSet(3);
    ds.MakeSet(4);
    ds.MakeSet(5);

    ds.Union(1, 2);
    ds.Union(3, 4);
    ds.Union(1, 4);

    cout << ds.Find(1) << endl;
    cout << ds.Find(2) << endl;
    cout << ds.Find(3) << endl;
    cout << ds.Find(4) << endl;
    cout << ds.Find(5) << endl;

    return 0;
}
