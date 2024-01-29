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

void print_preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << ' ';
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_inorder(Node* root)
{
    if (root == NULL)
        return;
    
    print_inorder(root->left);
    cout << root->data << ' ';
    print_inorder(root->right);
}

void print_postorder(Node* root)
{
    if (root == NULL)
        return;

    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->data << ' ';
}

int height(Node* root)
{
    if (root == NULL)
        return 0;

    else {

        int lheight = height(root->left);
        int rheight = height(root->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void print_current_level(Node* root, int level)
{
    if (root == NULL)
        return;

    if (level == 1)
        cout << root->data << " ";

    else if (level > 1) {

        print_current_level(root->left, level - 1);
        print_current_level(root->right, level - 1);
    }
}

void print_level_order(Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++) {

        print_current_level(root, i);
        cout << '\n';
    }
}

void print_level_order2(Node* root)
{

    if (root == NULL)
        return;

    queue<Node*> q;

    q.push(root);
 
    while (q.empty() == false) {

        int h = height(q.front());
        int x = h;
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
 
        if (node->left != NULL)
            q.push(node->left);

        if (node->right != NULL)
            q.push(node->right);

        h = height(q.front());
        if (x > h)
            cout << '\n';
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

    // print_preorder(root);
    // print_inorder(root);
    // print_postorder(root);
    print_level_order2(root);

    return 0;
}   
