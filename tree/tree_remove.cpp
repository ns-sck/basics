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

void delete_deepest(Node* root, Node* d_node)
{
    queue<Node*> q;
    q.push(root);
    Node* temp;

    while(!q.empty()) {

        temp = q.front();
        q.pop();

        if (temp == d_node) {

            temp = NULL;
            delete (d_node);
            return;
        }   
        if (temp->right) {

            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            } else {
                q.push(temp->right);
            }
        }
        if (temp->left) {

            if (temp->left == d_node) {
                
                temp->left = NULL;
                delete (d_node);
                return;
            } else {
                q.push(temp->left);
            }
        }
    }
}

Node* deletion(Node* root, int data)
{
    if (!root)
        return NULL;

    if (!root->left && !root->right) {

        if (root->data == data)
            return NULL;
        else
            return root;
    }

    queue<Node*> q;
    q.push(root);

    Node* temp;
    Node* key_node = NULL;

    while (!q.empty()) {
        
        temp = q.front();
        q.pop();

        if (temp->data == data)
            key_node = temp;

        if (temp->left)
            q.push(temp->left);
 
        if (temp->right)
            q.push(temp->right);

        if (key_node) {

            int x = temp->data;
            delete_deepest(root, temp);
            key_node->data = x;
        }
    }
    return root;
}

void print_inorder(Node* root)
{
    if (root == NULL)
        return;
    
    print_inorder(root->left);
    cout << root->data << ' ';
    print_inorder(root->right);
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

    deletion(root, 5);
    print_inorder(root);
    return 0;
}