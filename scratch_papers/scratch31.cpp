#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        Node* left;
        Node* right;
        int data;
        Node(int data) : left(nullptr), right(nullptr), data(data) {}
};

void BST_to_MaxHeap(Node* root, vector<int> arr, int* i)
{
    if(root == NULL)    
        return;
    BST_to_MaxHeap(root->left, arr, i);
    BST_to_MaxHeap(root->right, arr,i);
    root->data = arr[++*i];
   
}

void inorder_traversal(Node* root, vector<int>& arr)
{
    if(root == NULL)
        return;

    inorder_traversal(root->left, arr);
    arr.push_back(root->data);
    inorder_traversal(root->right, arr);
    
}

void convert(Node* root)
{
    vector<int> arr;
    int i = -1;
    inorder_traversal(root, arr);
    BST_to_MaxHeap(root, arr, &i);
}

int main ()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convert(root);
    
    cout << "bitti";
    return 0;
}