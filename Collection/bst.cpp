#include<iostream>

using namespace std;

class BSTNode{
public:
    BSTNode(int v) : val(v), left(NULL), right(NULL) {}
    void insert(int v) {
        if (v < val) {
            if (left == NULL) {
                left = new BSTNode(v);
            } else {
                left->insert(v);
            }
        } else {
            if (right == NULL) {
                right = new BSTNode(v);
            } else {
                right->insert(v);
            }
        }
    }

    bool search(int v) {
        if (v < val) {
            if (left == NULL) 
                return false;
            else
                return left->search(v); 
        } else if (v > val) {
            if (right == NULL)
                return false;
            else
                return right->search(v);
        } else {
            return true;
        }
    }

    void remove(int v, BSTNode *parent) {
        if (v < val) {
            if (left == NULL) {
                return;
            } else {
                left->remove(v, this);
            }
        } else if (v > val) {
            if (right == NULL) {
                return;
            } else {
                right->remove(v, this);
            }
        } else {
            if (left != NULL && right != NULL) {
                val = minValue();
                right->remove(val, this);
            } else if (parent->left == this) {
                parent->left = left ? left : right;
            } else if (parent->right == this) {
                parent->right = left ? left : right;
            }
        }
    }

    int minValue() {
        if (left == NULL) {
            return val;
        } else {
            return left->minValue();
        }
    }

    int val;
    BSTNode *left, *right;
};


int main() {
    
    BSTNode *root = new BSTNode(5);
    root->left = new BSTNode(2);
    root->right = new BSTNode(12);
    root->left->left = new BSTNode(-4);
    root->left->right = new BSTNode(3);
    root->right->left = new BSTNode(9);
    root->right->right = new BSTNode(21);
    root->right->right->left = new BSTNode(19);
    root->right->right->right = new BSTNode(25);

    cout << root->search(12) << endl;

    root->remove(12, NULL);

    cout << root->search(12) << endl;

    return 0;
}
