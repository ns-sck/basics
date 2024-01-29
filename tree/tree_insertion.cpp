#include <iostream>
#include <queue>
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

Node* insertNode(Node* root, int data)
{
    if (!root)

        root = newNode(data);
        return root;
        
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node* temp = q.front();
        q.pop();

        if (temp->left)
            q.push(temp->left);
        else {
            temp->left = newNode(data);
            return root;
        }
        if (temp->right)
            q.push(temp->right);
        else {
            temp->right = newNode(data);
            return root;
        }
    }
}

int main()
{

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    return 0;
}