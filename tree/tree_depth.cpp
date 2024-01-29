#include <iostream>
using namespace std;

class Node {

    public:

        int data;
        Node* left;
        Node* right;
};

Node* newNode(int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}


int max_depth(Node* root)
{
    if (root == NULL)
        return 0;
    else {
        int l_depth = max_depth(root->left);
        int r_depth = max_depth(root->right);

        if(l_depth > r_depth)
            return l_depth + 1;
        else
            return r_depth + 1;
    }   
}

int main()
{

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << max_depth(root);

    return 0;
}