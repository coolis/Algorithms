#include<iostream>
#include<vector>

using namespace std;

void quick_sort(vector<int> &A, int left, int right) {
    if (left > right) return;
    int pivot = A[right];
    int mid = left;
    for (int i=left; i<=right; i++) {
        if (A[i] <= pivot) {
            swap(A[i], A[mid++]);
        }
    }
    mid--;
    
    quick_sort(A, left, mid-1);
    quick_sort(A, mid+1, right);
}

int main() {
    int n;
    cin >> n;
    vector<int> in(n);
    for (int i=0; i<n; i++) {
        cin >> in[i];
    }
    quick_sort(in, 0, n-1);
    for (int i=0; i<n; i++) {
        cout << in[i] << " ";
    }
    cout << endl;
    return 0;
}
