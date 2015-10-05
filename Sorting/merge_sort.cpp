#include<iostream>
#include<vector>

using namespace std;

vector<int> merge_two(vector<int> A, vector<int> B) {
    vector<int> res;
    int p = 0, q = 0;
    while (p < A.size() && q < B.size()) {
        if (A[p] < B[q])
            res.push_back(A[p++]);
        else
            res.push_back(B[q++]);
    }
    while (p < A.size()) res.push_back(A[p++]);
    while (q < B.size()) res.push_back(B[q++]);
    return res;
}

vector<int> merge_sort(vector<int> &A) {
    if (A.size() == 1) return A;

    int mid = A.size()/2;
    vector<int> left(A.begin(), A.begin()+mid);
    vector<int> right(A.begin()+mid, A.end()); 
    left = merge_sort(left);
    right = merge_sort(right);

    // merge two array
    return merge_two(left, right);
}

int main() {
    int n;
    cin >> n;
    vector<int> in(n);
    for (int i=0; i<n; i++) {
        cin >> in[i];
    }
    in = merge_sort(in);
    for (int i=0; i<n; i++) {
        cout << in[i] << " ";
    }
    cout << endl;
    return 0;
}
