#include <iostream>
#include <vector>
using namespace std;

class Node {

    public:
        int depth;
        int balance;
        int data;
        Node* left;
        Node* right;
        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
        int rec(Node*);
};

int Node::rec(Node* root)
{
    if(!root->left && !root->right) {
        this->depth = 0;
        this->balance = 0;
        return 0;
    }

    int ld = root->left ? rec(root->left) : 0;
    int rd = root->right ? rec(root->right) : 0;
    int bal = abs(ld - rd);
    int dep = max(ld, rd) + 1;
    root->balance = bal; 
    root->depth = dep;
    return dep;
}

void greaterValues(vector<int> heap, int root, int key)
{
    if (heap[root] < key) {
        return;
    }
    if (heap[root] == key) {
        cout << heap[root] << ' ';
        return;
    }
    cout << heap[root] << ' ';
    if (2 * root + 1 < heap.size())
        greaterValues(heap, 2 * root + 1, key);
    if (2 * root + 2 < heap.size())
        greaterValues(heap, 2 * root + 2, key);
}

int main ()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(2);
    root->left->left->left = new Node(2);
    root->left->right = new Node(2);
    root->right = new Node(2);
    root->right->right = new Node(2);

    root->rec(root);

    vector<int> a = {20,15,10,7,9,4,6};
    greaterValues(a, 0, 11);
    return 0;
}